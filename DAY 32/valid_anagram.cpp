class Solution{	
	public:
		bool anagramStrings(string& s,string t){
            int freqS[26] = {0} ;
            int freqT[26] = {0} ;
            int n = s.length();
            if(s.length() != t.length()) return false;
            for(int i = 0 ; i<n ; i++){
                freqS[s[i] - 'a']++;
                freqT[t[i] - 'a']++;
            }
            for(int i = 0 ; i<26 ; i++){
                if(freqS[i] != freqT[i]) return false;
            }
			return true;
		}
};