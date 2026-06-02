class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int mini = arr[0] , profit = 0;
        for(int i = 1 ; i<n ; i++){
            int cost = arr[i] - mini;
            profit = max(cost , profit);
            mini = min(arr[i] , mini);
        }
        return profit;
    }
};

