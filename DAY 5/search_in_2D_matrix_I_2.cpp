class Solution{
public:
    bool bs(vector<vector<int>> &mat ,int row, int target , int n,int m){
        int low = 0 ,high = m-1;
        while(low <= high){
           int mid =  (low + high)/2; 
           if(mat[row][mid] == target){
             return true;
           }else if (mat[row][mid] < target){
              low = mid + 1;
           }else{
              high = mid - 1;
           }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>> &mat, int target){
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ; i<n ; i++){
            if(mat[i][0] <= target && target <= mat[i][m-1]){
                return bs(mat,i,target,n,m);
            }
        }
        return false;
    }
};