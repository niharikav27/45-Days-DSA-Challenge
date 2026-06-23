class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arr, int k) {
        vector<int> result;
        priority_queue< pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        for (int i = 0; i < k; i++) {
            if (!arr[i].empty()) {
                pq.push({arr[i][0], {i, 0}});
            }
        }
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int val = top.first;
            int row = top.second.first;
            int col = top.second.second;
            result.push_back(val);
            if (col + 1 < arr[row].size()) {
                pq.push({arr[row][col+1], {row, col+1}});
            }
        }
        return result;
    }
};