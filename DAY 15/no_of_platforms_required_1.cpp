class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        int n = Arrival.size();
        int ans = 1;
        for(int i = 0 ; i<n ; i++){
            int count = 1;
            for(int j = 0 ; j<n ; j++){
                if(i != j){
                    if((Arrival[i] >= Arrival[j] && Departure[j] >= Arrival[i])){
                        count++;
                    }
                    ans = max(ans , count);
                }
            }
        }
        return ans;
    }
};