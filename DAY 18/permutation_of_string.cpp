class Solution {
public:
    void solve(int index ,string s , vector<string> &ans) {
        if (index == s.size()) {
            ans.push_back(s);
            return;
        }
        unordered_set<char> used;
        for (int i = index; i < s.size(); i++) {
            if (used.count(s[i]))
                continue;
            used.insert(s[i]);
            swap(s[index], s[i]);
            solve(index + 1, s, ans);
            swap(s[index], s[i]);
        }
    }
    vector<string> permuteUnique(string s) {
        vector<string> ans;
        solve(0, s, ans);
        sort(ans.begin(), ans.end());   
        return ans;
    }
};
