class Solution {
public:
    bool ls(vector<int>& nums ,int x){
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            if(nums[i] == x){
                return true;
            }
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        for(int i = 0 ; i<n ; i++){
            int x = nums[i];
            int cnt = 1;
            while(ls(nums,x+1) == true){
                x = x+1;
                cnt = cnt + 1;
            }
            longest = max(longest , cnt);
        }
        return longest;
    }
};