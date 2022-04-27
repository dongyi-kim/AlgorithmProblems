#include<vector>
using namespace std;

class Solution {
public:
    enum Result{
        NONE,
        TRUE,
        FALSE
    };
    vector<vector<Result> > memo;

    
    bool dp(int i, int j, const string &s, const string &p){
        if( i >= s.length() and j >= p.length()) return true;
        if( j >= p.length() ) return false;
        if(memo[i][j] != NONE) return memo[i][j] == TRUE;
        bool result = false;
        bool match = i < s.length() and (s[i] == p[j] or p[j] == '.');
        if(j + 1 < p.length() and p[j+1] == '*'){
            result |= dp(i,j+2, s, p);
            if(match) result |= dp(i+1, j, s, p);
        }else if(match){
            result |= dp(i+1, j+1, s, p);
        }
        
        memo[i][j] = result ? TRUE : FALSE;
        return memo[i][j] == TRUE;
    }
    bool isMatch(string s, string p) {
        memo.resize(s.length()+1, vector<Result>(p.length()+1, NONE));
        return dp(0, 0, s, p);
    }
};