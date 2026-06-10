/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* &linkedList1, ListNode* &linkedList2) {
            ListNode* dummyhead = new ListNode(-1);
            ListNode* curr = dummyhead;
            ListNode* temp1 = linkedList1;
            ListNode* temp2 = linkedList2;
            int carry = 0;
            while(temp1 != NULL || temp2 != NULL){
                int sum = carry;
                if(temp1) sum += temp1->data;
                if(temp2) sum += temp2->data;
                ListNode* newNode = new ListNode(sum % 10);
                carry = sum /10;
                curr->next = newNode;
                curr = curr -> next;
                if(temp1) temp1 = temp1 -> next;
                if(temp2) temp2 = temp2->next;
            }
            if(carry){
                ListNode* newNode = new ListNode(carry);
                curr -> next = newNode;
            }
            return dummyhead->next;
        }
};