class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1.0) return 1;
        long long num = n;
        if (num<0){
            x = 1/x;
            num = -1*1LL*num;
        }
        if (num % 2 == 1){
            return x* myPow(x,num-1);
        }
        return myPow(x*x , num/2);
    }
};