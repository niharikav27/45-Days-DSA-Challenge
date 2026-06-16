class Solution{    
    public:
    int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
        int n = Student.size();
        int m = Cookie.size();
        int l = 0, r = 0;
        sort(Student.begin(), Student.end());
        sort(Cookie.begin(), Cookie.end());
        while (l < n && r < m) {
            if (Cookie[r] >= Student[l]) {
                l++;
            }
            r++;
        }
        return l;
    }
};