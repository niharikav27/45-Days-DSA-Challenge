class Solution {
public:
    int kthLargestElement(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        while(true){
            int pivotIndex = randomIndex(l,r);
            pivotIndex = partitionAndReturnIndex(nums,pivotIndex,l,r);
            if(pivotIndex == k-1){
                return nums[pivotIndex];
            }else if(k-1 < pivotIndex){
                r =pivotIndex - 1;
            }else{
                l = pivotIndex + 1;
            }
        }
    }
    int partitionAndReturnIndex(vector<int>& nums,int pivotIndex,int l ,int r){
        swap(nums[l] , nums[pivotIndex]);
        int index = l + 1;
        for(int i = l + 1 ; i <= r ; i++){
            if(nums[i] > nums[l]){
                swap(nums[index] , nums[i]);
                index++;
            }
        }
        swap(nums[l] , nums[index - 1]);
        return index-1;
    }
    int randomIndex(int l, int r) { 
        int len = r - l + 1; 
        return (rand() % len) + l;
    }
};