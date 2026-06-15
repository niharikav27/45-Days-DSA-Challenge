class Solution{
    public:
    static bool comparator(const pair<int,int> &a , const pair<int,int> &b){
        return a.second < b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end){
        int n = start.size();
        vector<pair<int,int>> meetings;
        for(int i = 0 ; i<n ; i++){
            meetings.push_back({start[i] , end[i]});
        }
        sort(meetings.begin() , meetings.end() , comparator);
        int freetime = meetings[0].second;
        int count = 1;
        for(int i =1 ; i<n ; i++){
            if(meetings[i].first > freetime){
                count++;
                freetime = meetings[i].second;
            }
        }
        return count;
    }
};