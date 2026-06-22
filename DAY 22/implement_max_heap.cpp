class Solution{
    public:
        vector<int>arr;
        int cnt = 0;
        void initializeHeap(){
        }
        void heapify_up(int index){
            int parent_ind = (index - 1)/2;
            if(index > 0 && arr[index] > arr[parent_ind]){
                swap(arr[index] , arr[parent_ind]);
                heapify_up(parent_ind);
            }
            return;
        }
        void heapify_Down(int index) {
            int n = arr.size();
            int largest_Ind = index; 
            int left_Child_Ind = 2*index + 1;
            int right_Child_Ind = 2*index + 2;

            if(left_Child_Ind < n && arr[left_Child_Ind] > arr[largest_Ind]) 
                largest_Ind = left_Child_Ind;

            if(right_Child_Ind < n && arr[right_Child_Ind] > arr[largest_Ind]) 
                largest_Ind = right_Child_Ind;

            if(largest_Ind != index) {
                swap(arr[largest_Ind] , arr[index]);
                heapify_Down(largest_Ind);
            }
            return; 
        }
        void insert(int key){
            arr.push_back(key);
            heapify_up(cnt);
            cnt = cnt + 1;
            return;
        }

        void changeKey(int index, int new_val){
            if(arr[index] < new_val){
                arr[index] = new_val;
                heapify_up(index);
            }else{
                arr[index] = new_val;
                heapify_Down(index);
            }
            return;
        }

        void extractMax(){
            int element = arr[0];
            swap(arr[0] , arr[cnt - 1]);
            arr.pop_back();
            cnt = cnt - 1;
            heapify_Down(0);
        }

        bool isEmpty(){
            return (cnt == 0);
        }

        int getMax(){
            return arr[0];
        }

        int heapSize(){
            return cnt;
        }
};