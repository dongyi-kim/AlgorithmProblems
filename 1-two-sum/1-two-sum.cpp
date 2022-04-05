#include<algorithm>
#include<utility>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2);
        unordered_map<int, int> dict;
        for(int i = 0 ; i < nums.size(); i += 1){
            int x = nums[i];
            int y = target - x;
            if(dict.count(y) > 0){
                answer[0] = i;
                answer[1] = dict[y];
                break;
            }
            dict[x] = i;
        }
        return answer;
    }
};