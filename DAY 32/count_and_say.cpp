class Solution {
  public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string prev = countAndSay(n-1);
        int cnt = 1;
        string ans = "";
        for(int i = 1 ; i<prev.length() ; i++){
            if(prev[i] == prev[i-1]) cnt++;
            else{
                ans.push_back('0' + cnt); 
                ans.push_back(prev[i-1]); 
                cnt = 1;
            }
        }
        ans.push_back('0' + cnt);
        ans.push_back(prev[prev.length()-1]); 
        return ans;
    }   
};