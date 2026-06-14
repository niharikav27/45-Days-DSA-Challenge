class Solution
{
public:
    vector<int>findprefixmax(vector<int> &height , int n){
        vector<int>prefixmax(n);
        prefixmax[0] = height[0];
        for(int i = 1 ; i<n ; i++){
            prefixmax[i] = max(prefixmax[i-1] , height[i]);
        }
        return prefixmax;
    }
    vector<int>findsuffixmax(vector<int> &height , int n){
        vector<int>suffixmax(n);
        suffixmax[n-1] = height[n-1];
        for(int i = n-2 ; i>= 0 ; i--){
            suffixmax[i] = max(suffixmax[i+1] , height[i]);
        }
        return suffixmax;
    }
    int trap(vector<int> &height){
        int n = height.size();
        int total = 0;
        vector<int>leftmax = findprefixmax(height,n);
         vector<int>rightmax = findsuffixmax(height,n);
        for(int i = 0 ; i<n ; i++){
            if(height[i] < leftmax[i] && height[i] < rightmax[i]){
                total += min(leftmax[i] , rightmax[i]) - height[i];
            }
        }
        return total;
    }
};