
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;
        while( i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                merged.push_back(nums1[i]);
                i += 1;
            }else{
                merged.push_back(nums2[j]);
                j += 1;
            }
        }
        for(;i<nums1.size();i+=1) merged.push_back(nums1[i]);
        for(;j<nums2.size();j+=1) merged.push_back(nums2[j]);
        int size = merged.size();
        double median = (size % 2 == 1) ? merged[size/2] : (merged[size/2]+merged[size/2-1])/2.0;
        return median;
    }
};