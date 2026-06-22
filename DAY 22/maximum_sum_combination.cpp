class Solution {
public:
  vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> st;
        pq.push({nums1[n-1] + nums2[n-1], {n-1, n-1}});
        st.insert({n-1, n-1});
        vector<int> ans;

        while(k--) {
           auto top = pq.top();
           pq.pop();
           int sum = top.first;
           int i = top.second.first;
           int j = top.second.second;
           ans.push_back(sum);

           if(i - 1 >= 0 && st.find({i-1, j}) == st.end()) {
               pq.push({nums1[i-1] + nums2[j], {i-1, j}});
               st.insert({i-1, j});
            }
            if(j - 1 >= 0 && st.find({i, j-1}) == st.end()) {
                pq.push({nums1[i] + nums2[j-1], {i, j-1}});
                st.insert({i, j-1});
            }
        }
        return ans;
    }    
};

  
