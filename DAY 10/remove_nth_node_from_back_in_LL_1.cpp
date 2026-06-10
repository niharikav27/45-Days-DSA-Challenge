/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int cnt = 0;
       ListNode* temp = head;
       while(temp != NULL){
          cnt++;
          temp = temp -> next;
       }
       if(cnt == n){
         ListNode* newhead = head -> next;
         delete(head);
         return newhead;
       }
       int res = cnt - n;
       temp = head;
       while(temp != NULL){
          res--;
          if(res == 0) break;
          temp = temp -> next;
       }
       ListNode* delnode = temp -> next;
       temp -> next = temp->next ->next;
       delete (delnode);
       return head;
    }
};