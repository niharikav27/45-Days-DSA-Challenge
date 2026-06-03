class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                ans[j][n-1-i] = matrix[i][j];
            }
        }
        return ans;
    }
};