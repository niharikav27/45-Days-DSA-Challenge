class Solution {
public:
    vector<int> dp;
    bool solve(int idx, string &s, vector<string> &wordDict) {
        if (idx == s.size())
          return true;
        if (dp[idx] != -1)
            return dp[idx];
        for (string word : wordDict) {
            int len = word.size();
            if (idx + len <= s.size() &&
                s.substr(idx, len) == word) {
                if (solve(idx + len, s, wordDict))
                    return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size(), -1);
        return solve(0, s, wordDict);
    }
};