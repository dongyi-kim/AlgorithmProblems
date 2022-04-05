#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> count;
        int answer = 0;
        for(int i = 0, j = -1 ; i < s.length(); i += 1){
            while( j<i || j+1 < s.length() && count[s[j+1]] == 0){
                count[s[j+1]] += 1;
                j += 1;
            }
            answer = max(answer, j - i + 1);
            count[s[i]] -= 1;
        }
        return answer;
    }
};