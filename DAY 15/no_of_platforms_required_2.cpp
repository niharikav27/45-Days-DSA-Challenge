class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        int n = Arrival.size();
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());
        int ans = 1;
        int count = 1;
        int i = 1, j = 0;
        while (i < n && j < n) {
            if (Arrival[i] <= Departure[j]) {
                count++;
                i++;
            } else {
                count--;
                j++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};