class Solution{   
public:
    bool func(int ind, int target, vector<int>& arr) {
        int n = arr.size();
        vector<bool> prev(target + 1, false);
        prev[0] = true;
        if (arr[0] <= target) {
            prev[arr[0]] = true;
        }
        for (int ind = 1; ind < n; ind++) {
            vector<bool> cur(target + 1, false);
            cur[0] = true;
            for (int i = 1; i <= target; i++) {
                bool notTaken = prev[i];
                bool taken = false;
                if (arr[ind] <= i) {
                    taken = prev[i - arr[ind]];
                }
                cur[i] = notTaken || taken;
            }
            prev = cur;
        }
        return prev[target];
    }    
    bool isSubsetSum(vector<int>arr, int target){
        return func(arr.size() - 1, target, arr);
    }
};