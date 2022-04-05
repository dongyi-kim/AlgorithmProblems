#include<algorithm>
#include<utility>
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2);
        vector<pair<int, int> > data;
        for(int i = 0 ; i < nums.size(); i += 1) data.emplace_back(nums[i], i);
        sort(data.begin(), data.end());
        for(int i = 0 ; i < nums.size(); i += 1){
            int x = data[i].first;
            int x_idx = data[i].second;
            int y = target - x;
            auto yit = lower_bound(data.begin()+i+1, data.end(), make_pair(y, 0));
            if(yit == data.end()) continue;
            if(yit->first == y){
                answer[0] = x_idx;
                answer[1] = yit->second;
            }
        }
        return answer;
    }
};