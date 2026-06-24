class ArrayQueue {
    int* arr;
    int start, end;
    int currSize, maxSize;
public:
    ArrayQueue() {
        arr = new int[10];
        start = -1;
        end = -1;
        currSize = 0;
        maxSize = 10;
    }
    
    void push(int x) {
        if(currSize == maxSize) return;
        if(currSize == 0){
            start= 0, end = 0;
        }else{
            end = (end + 1)% maxSize;
        }
        arr[end] = x , currSize += 1;
    }
    
    int pop() {
        if(currSize == 0) return -1;
        int element = arr[start];
        if(currSize == 1){
            start = end = -1;
        }else{
            start = (start + 1) % maxSize;
        } 
        currSize -= 1;
        return element;
    }
    
    int peek() {
        if(currSize == 0) return -1;
        return arr[start];
    }
    
    bool isEmpty() {
        return (currSize == 0);
    }
};