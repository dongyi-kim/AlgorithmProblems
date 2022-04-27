#include<algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        pair<int,int > answer(0, 0);
        for(int i = 0; i < s.length() ; i ++){
            for(int l = i, r = i; l >= 0 && r < s.length(); l --, r++ ){
                if(s[l] != s[r]) break;
                if(answer.second - answer.first < r - l ){
                    answer.first = l;
                    answer.second = r;
                }
            }
            for(int l = i, r = i + 1; l >= 0 && r < s.length(); l --, r++ ){
                if(s[l] != s[r]) break;
                if(answer.second - answer.first < r - l ){
                    answer.first = l;
                    answer.second = r;
                }
            }
        }
        return s.substr(answer.first, answer.second - answer.first + 1);
    }
};