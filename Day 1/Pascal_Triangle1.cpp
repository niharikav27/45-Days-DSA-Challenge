class Solution {
public:
    int pascalTriangleI(int r, int c) {
        long long result = 1;
        int n = r-1;
        int m = c-1;
        for(int i=0 ; i<m ; i++){
            result = result * (n - i);
            result = result/(i + 1);
        }
    return result;
    }
};