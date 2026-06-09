// Definition of singly linked list:
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int data1)
//     {
//         val = data1;
//         next = NULL;
//     }
//     ListNode(int data1, ListNode *next1)
//     {
//         val = data1;
//         next = next1;
//     }
// };

class Solution {
public:
    void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " "; 
        temp = temp->next; 
    }
    cout << endl;
}
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>arr;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 != NULL){
            arr.push_back(temp1 -> val);
            temp1 = temp1 -> next;
        }
        while(temp2 != NULL){
            arr.push_back(temp2 -> val);
            temp2 = temp2 -> next;
        }
        sort(arr.begin(),arr.end());
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        for(int i = 0; i < arr.size(); i++){
            temp->next = new ListNode(arr[i]); 
            temp = temp->next; 
        }
        return dummyNode->next; 
    }
};