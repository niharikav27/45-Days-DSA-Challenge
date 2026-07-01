class Solution{
    public:
        vector<int> computeLPS(string s) {
            int n = s.size(); 
            vector<int> LPS(n, 0);
            int i = 1, j = 0;
            while(i < n) {
                if(s[i] == s[j]) {
                    LPS[i] = j+1;
                    i++, j++;
                }
                else {
                    while(j > 0 && s[i] != s[j]) {
                        j = LPS[j-1];
                    }
                    if(s[i] == s[j]) {
                        LPS[i] = j+1;
                        j++;
                    }
                    i += 1;
                }
            }
            return LPS;
        }    
        vector <int> search(string pat, string txt){
            string s = pat + '$' + txt;
            vector<int> LPS = computeLPS(s);
            int n = txt.size(), m = pat.size();
            vector<int> ans;
            for(int i = m+1; i < s.size(); i++) {
                if(LPS[i] == m) ans.push_back(i - 2*m);
            }
            return ans;
        }    
};