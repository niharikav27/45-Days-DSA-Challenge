class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int longest = 1;
        int cnt = 0;
        int last_smaller = INT_MIN;
        for(int i = 0 ; i<n ; i++){
            if(nums[i] - 1 == last_smaller){
                cnt = cnt + 1;
                last_smaller = nums[i];
            }else if(nums[i] != last_smaller){
                cnt = 1;
                last_smaller = nums[i];
            }
            longest = max(longest , cnt);
        }
        return longest;
    }
};