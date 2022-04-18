#include<cmath>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double ret = (abs(n)%2==1) ? x : 1;
        if( n < 0 ){
            return 1 / (ret * myPow(x*x, -(n/2) ));   
        }else{
            return 1 * ret * myPow(x*x, n/2);   
        }
        
    }
};