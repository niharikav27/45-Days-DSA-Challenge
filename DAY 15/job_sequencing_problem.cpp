class Solution{  
  public:  
    bool static compare(const vector<int> &a, const vector <int> &b) {
        return a[2] > b[2];
    }
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        sort(Jobs.begin(), Jobs.end(), compare);
        int n = Jobs.size();
        int maxDeadline = -1;
        for(auto it : Jobs) {
            maxDeadline = max(maxDeadline, it[1]);
        }
        vector<int> hash(maxDeadline, -1);
        int cnt = 0;
        int totalProfit = 0;
        for (int i = 0; i < n; i++) {
            for (int j = Jobs[i][1] - 1; j >= 0; j--) { 
                if (hash[j] == -1) {
                    cnt++;
                    hash[j] = Jobs[i][0]; 
                    totalProfit += Jobs[i][2]; 
                    break;
                }
            }
        }
        return {cnt,totalProfit};
    } 
};