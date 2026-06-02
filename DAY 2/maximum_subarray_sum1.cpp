class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0 ; i<n ; i++){
            for(int j = i ; j<n ; j++){
                int sum = 0;
                for(int k = i ; k <= j ; k++){
                    sum += nums[k];
                }
                maxi = max(sum , maxi);
            }
        }
        return maxi;
    }
};