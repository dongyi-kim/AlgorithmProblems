#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<vector>

#define pi pair<long long, int>
#define mp(a,b) make_pair(a,b)


using namespace std;


void test_case()
{
    int n; cin >> n;
    
    priority_queue<pi > maxq;
    priority_queue<pi > minq;
    
    vector<bool> chk(n,false);
    int cnt = 0;
    int rem = 0;
    for(int i=0;i<n;i++)
    {
        char c;
        long long num;
        cin >> c;
        cin >> num;
        if( c == 'I')
        {
            minq.push(mp(-num, cnt));
            maxq.push(mp(num, cnt));
            chk[cnt]=true;
            cnt++;
            rem ++;
        }else
        {
            int idx;
            if(rem == 0)
                continue;
            
            while(maxq.size() > 0 && chk[maxq.top().second] == false)
                maxq.pop();
            while(minq.size() > 0 && chk[minq.top().second] == false)
                minq.pop();
            
            if( num == -1)
            {
                idx = minq.top().second;
                minq.pop();
            }else
            {
                idx = maxq.top().second;
                maxq.pop();
            }
            rem --;
            
            chk[idx] = false;
            while(maxq.size() > 0 && chk[maxq.top().second] == false)
                maxq.pop();
            while(minq.size() > 0 && chk[minq.top().second] == false)
                minq.pop();
        }
    }
    
    if(rem==0)
        printf("EMPTY\n");
    else
        printf("%lld %lld\n",maxq.top().first, -minq.top().first);
   
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
        test_case();
    return 0;
}