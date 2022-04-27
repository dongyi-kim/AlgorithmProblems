#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<char> > chars = {
            {}, 
            {}, 
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };
        
    vector<char> buffer;
    void gen(int depth, const string &digits, vector<string> &output){
        if(depth == digits.length()){
            output.emplace_back( buffer.data(), buffer.size() );
            return;
        }else{
            int digit = digits[depth] - '0';
            for(char c : chars[digit]){
                buffer.push_back(c);
                gen(depth+1, digits, output);
                buffer.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){ return {}; }
        vector<string> output;
        gen(0, digits, output);
        return output;
    }
};