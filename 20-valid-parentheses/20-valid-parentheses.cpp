#include<vector>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        string open = "({[";
        string close = ")}]";
        
        for(char c : s){
            if(open.find(c) < open.length()){
                v.push_back(c);
            }else{
                char expected = open[close.find(c)];
                if(v.size() > 0 && v.back() == expected){
                    v.pop_back();
                }else{
                    return false;
                }
            }
        }
        return v.size() == 0;
    }
};