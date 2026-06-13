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
    ListNode* findNthNode(ListNode* temp , int k){
        int cnt = 1;
        while(temp != NULL){
          if(cnt == k) return temp;
          cnt++;
          temp = temp -> next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
       if(head == NULL || k == 0) return head;
       ListNode* tail = head;
       int len = 1;
       while(tail -> next != NULL){
         tail = tail -> next;
         len += 1;
       }
       if(k % len == 0) return head;
       k = k % len;
       tail -> next = head;
       ListNode* newLastNode = findNthNode(head,len-k);
       head = newLastNode -> next;
       newLastNode->next = NULL;
       return head;
    }
};