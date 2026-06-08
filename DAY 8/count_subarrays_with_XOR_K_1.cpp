class Solution {
public:
    int subarraysWithXorK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                int xorr = 0;

                for (int l = i; l <= j; l++) {
                    xorr ^= nums[l];
                }

                if (xorr == k) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};