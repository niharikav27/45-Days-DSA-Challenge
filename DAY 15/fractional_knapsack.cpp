class Solution {
public:
    double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {
        vector<pair<double, int>> ratio;
        for (int i = 0; i < val.size(); i++)
            ratio.push_back({(double)val[i] / wt[i], i});

        sort(ratio.rbegin(), ratio.rend());
        double totalValue = 0.0;
        for (auto &r : ratio) {
            int i = r.second;
            if (wt[i] <= capacity) {
                totalValue += val[i];
                capacity -= wt[i];
            } else {
                totalValue += val[i] * ((double)capacity / wt[i]);
                break;
            }
        }
        return round(totalValue * 1e6) / 1e6; 
    }
};