class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; i++) nums.push_back(i);
        vector<int> fact(n, 1);
        for(int i = 1; i < n; i++) fact[i] = fact[i-1] * i;
        k--;
        string ans = "";
        for(int i = n-1; i >= 0; i--) {
            int index = k / fact[i];
            ans += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k %= fact[i];
        }
        return ans;
    }
};