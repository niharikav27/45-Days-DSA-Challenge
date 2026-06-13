/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode()
    {
        val = 0;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        random = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* r)
    {
        val = data1;
        next = next1;
        random = r;
    }
};
*/

class Solution {
public:
    void insertCopyInBetween(ListNode* head){
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* nextElement = temp -> next;
            ListNode* copy = new ListNode(temp -> val);
            copy->next = nextElement;
            temp->next = copy;
            temp = nextElement;
        }
    }
    void connectRandomPointers(ListNode* head){
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* copyNode = temp -> next;
            if(temp -> random){
                copyNode -> random = temp->random->next;
            }else{
                copyNode->random = nullptr;
            }
            temp = temp -> next -> next; 
        }
    }
    ListNode* getDeepCopyList(ListNode* head){
        ListNode* temp = head;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;
        while(temp != NULL){
            res->next = temp->next;
            res=res->next;
            temp -> next = temp->next->next;
            temp = temp -> next;
        }
        return dummyNode -> next;
    }
    ListNode* copyRandomList(ListNode* head) {
        insertCopyInBetween(head); 
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};