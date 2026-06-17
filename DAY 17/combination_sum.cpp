class Solution {
public:
    void func(vector<int>& v, int i, int sum, vector<int>& v2, vector<vector<int>>& ans) {
        if (sum == 0) {
            ans.push_back(v2);
            return;
        }
        if (sum < 0) {
            return;
        }
        if (i < 0) {
            return;
        }
        func(v, i - 1, sum, v2, ans);
        v2.push_back(v[i]);
        func(v, i, sum - v[i], v2, ans);
        v2.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        func(candidates, candidates.size() - 1, target, v, ans);
        return ans;
    }
};