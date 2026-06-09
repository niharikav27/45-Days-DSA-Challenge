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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(temp1 != NULL  && temp2 != NULL){
            if(temp1->val < temp2->val){
                temp -> next = temp1;
                temp = temp1;
                temp1 = temp ->next;
            }else{
                temp -> next = temp2;
                temp = temp2;
                temp2 = temp2 ->next;
            }
        }
        if (temp1 != NULL) {
            temp->next = temp1;
        } else {
            temp->next = temp2;
        }
        return dummyNode -> next;
    }
};