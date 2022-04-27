class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int x = -1;
        for(int i = n - 2 ; i >= 0 ; i -= 1 ){
            if(nums[i] < nums[i+1]){
                x = i; break;
            }
        }
        if( x == -1 ){
            reverse(nums.begin(), nums.end());
            return;
        }
        int y = -1 ;
        for(int i = x + 1; i < n ; i += 1){
            if(nums[x] >= nums[i]) continue;
            if(y == -1) y = i;
            if(nums[i] <= nums[y] ){
                y = i;
            }
        }
        swap(nums[y], nums[x]);
        reverse(nums.begin()+x+1,nums.end());
    }
};