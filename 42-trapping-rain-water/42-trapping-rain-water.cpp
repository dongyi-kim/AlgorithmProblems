class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 1) return 0;
        int area =0;
        
        vector<pair<int, int> > wall;
        
        int i = 0;
        int j = height.size() - 1;
        
        int hi = height[i];
        int hj = height[j];
        
        while (i < j ){
            int target = -1;
            if(height[i] >= height[j]){
                target = --j;
                area += max(0, min(hi, hj) - height[target]);
                hj = max(hj, height[j]);
            }else{
                target = ++i;
                area += max(0, min(hi, hj) - height[target]);
                hi = max(hi, height[i]);
            }
            
        }
        
        return area;
    }
};