class Solution {
public:
    void insertSorted(stack<int>& st, int x) {
        if (st.empty() || st.top() <= x) {
            st.push(x);
            return;
        }
        int t = st.top(); st.pop();
        insertSorted(st, x);
        st.push(t);
    }    
    void sortStack(stack<int> &st) {
        if (st.size() <= 1) return;
        int x = st.top();
        st.pop();
        sortStack(st);
        insertSorted(st, x);
    }
};