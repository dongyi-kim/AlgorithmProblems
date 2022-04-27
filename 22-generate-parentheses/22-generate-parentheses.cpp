#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        if( n == 0){
            return {""};
        }else{
            for(int c = 0 ; c < n ; c += 1){
                for(string& left : generateParenthesis(c)){
                    for(string& right : generateParenthesis(n-1-c)){
                        answer.push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        return answer;
        
    }
};