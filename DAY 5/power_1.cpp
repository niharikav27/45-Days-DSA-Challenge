class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1.0) return 1;
        long long temp = n;
        if (n<0){
            x = 1/x;
            temp = -1*1LL*n;
        }
        double ans = 1;
        for(long long i = 0; i<temp ; i++){
            ans = ans * x;
        }
        return ans;
    }
};