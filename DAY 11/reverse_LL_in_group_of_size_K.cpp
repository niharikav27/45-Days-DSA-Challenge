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
    ListNode* reverseLinkedList(ListNode *head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* findkthNode(ListNode* temp , int k){
        k -= 1;
        while(temp != NULL && k>0){
            k--;
            temp = temp -> next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp != NULL){
            ListNode* kthNode = findkthNode(temp,k);
            if(kthNode == NULL){
                if(prevLast)prevLast -> next = temp;
                break;
            }
            ListNode* nextNode = kthNode -> next;
            kthNode -> next = NULL;
            reverseLinkedList(temp);
            if(temp == head){
                head = kthNode;
            }else{
                prevLast -> next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
            
        }
        return head;
    }
};