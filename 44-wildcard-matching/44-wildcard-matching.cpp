class Solution {
public:
    vector<vector<int> > memo;
    bool isMatch(int i, int j, const string &s, const string & p){
        int n = s.length();
        int m = p.length();
        if( i >= n and j >= m ) return true;
        else if( j>= m ) return false;
        if( i <= n and j <= m and memo[i][j] != -1) return memo[i][j];
        bool result = false;
        
        if( p[j] == '*') {
            if( i < n ) result |= isMatch(i+1,j,s, p);
            result |= isMatch(i, j+1, s, p);
        }  
        else if( i < n and (p[j] == s[i] or p[j] == '?')) result |= isMatch(i+1,j+1, s, p);
            
        return memo[i][j] = result;
    }
    bool isMatch(string s, string p) {
        memo.clear();
        memo.resize(s.length() + 1, vector<int>(p.length() + 1, -1));
        return isMatch(0, 0, s, p);
    }
};