class ArrayStack {
private:
    int* stack;
    int topInd;
    int n;
public:
    ArrayStack(int size = 1000) {
        n = size;
        stack = new int[n];
        topInd = -1;
    }
    
    void push(int x) {
        if(topInd >= n-1 ){
            return;
        } 
        topInd = topInd + 1;
        stack[topInd] = x;   
    }
    
    int pop() {
        if(topInd == -1) return -1;
        return stack[topInd--];
    }
    
    int top() {
        if(topInd == -1) return -1;
        return stack[topInd];
    
    }
    
    bool isEmpty() {
        return topInd == -1;
    }
};