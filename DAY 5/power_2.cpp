class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1.0) return 1;
        long long num = n;
        if (n<0){
            x = 1/x;
            num = -1*1LL*n;
        }
        double ans = 1;
        while(num > 0){
            if(num % 2 == 1){
                ans =ans * x;
                num = num - 1;
            }else{
                x= x*x;
                num = num /2;
            }
        }
        return ans;
    }
};