
class Solution {
public:
    
    int leq(vector<int>& v, int value){
        if(value < v.front()) return 0;
        int l = 0;
        int r = v.size()-1;
        while(l < r){
            int m = (l+r+1)/2;
            if(v[m] <= value){
                l = m;
            }else{
                r = m - 1;
            }
        }
        return l + 1;
    }
    
    int geq(vector<int> & v, int value){
        if(value > v.back()) return 0;
        return v.size() - leq(v, value-1);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto& smaller = (nums1.size() < nums2.size()) ? nums1 : nums2;
        auto& bigger = (nums1.size() < nums2.size()) ? nums2 : nums1;
        if(smaller.size() == 0){
            int m = bigger.size()/2;
            return (bigger.size()%2==1) ? bigger[m] : (bigger[m] + bigger[m-1])/2.0;
        }
        
        int l = min(nums1.front(), nums2.front());
        int r = max(nums1.back(), nums2.back());
        int n = nums1.size() + nums2.size();
        int padding = ( n + 1 ) / 2;
        int cand1 = 123456789;
        int cand2 = -123456789;
        
        while(l <= r ){
            int m = (l + r) / 2;
            int leq_cnt = leq(nums1, m) + leq(nums2, m);
            if(leq_cnt < padding){
                l = m + 1;
            }else{ 
                cand1 = min(cand1,m);
                r = m - 1;
            }
        }
        
        l = min(nums1.front(), nums2.front());
        r = max(nums1.back(), nums2.back());
        while(l <= r){
            int m = ( l + r ) / 2;
            int geq_cnt = geq(nums1, m) + geq(nums2, m);
            if(geq_cnt < padding){
                r = m - 1;
            }else{ 
                cand2 = max(cand2,m);
                l = m + 1;
            }
        }

        return (cand1+cand2)/2.0;
    }
};