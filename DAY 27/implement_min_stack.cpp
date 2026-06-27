
class MinStack {
    stack <int> st;
    int mini;
public:
    MinStack() {
    }

  void push(int value) {
    if(st.empty()) {
        mini = value;
        st.push( value );
        return;
    }
    if(value > mini) {
        st.push(value);
    }
    else {
        st.push(2 * value - mini);
        mini = value;
    }
  }

  void pop() {
    if(st.empty()) return;
    int x = st.top();
    st.pop();
    if(x < mini) {
        mini = 2 * mini - x;
    }
  
  }

  int top() {
    if(st.empty()) return -1;
    int x = st.top();
    if(mini < x) return x;
    return mini;
  
  }

  int getMin() {
    return mini;
  }
};