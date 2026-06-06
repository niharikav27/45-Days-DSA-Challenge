class Solution {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mpp;
        int mini = (n/3) + 1;
        for(int i = 0 ; i<n ; i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] == mini){
                ans.push_back(nums[i]);
            }
            if (ans.size() == 2) {
                break;
            }
        }
        return ans;
    }
};