/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                res->child = list1;
                res = list1;
                list1 = list1->child;
            }
            else{
                res->child = list2;
                res = list2;
                list2 = list2->child;
            }
            res->next = NULL;
        }
        if(list1){
            res->child = list1;
        } else {
            res->child = list2;
        }
        if(dummyNode->child){
            dummyNode->child->next = NULL;
        }
        return dummyNode->child;
    }
    ListNode* flattenLinkedList(ListNode* &head) {
       if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* mergedHead = flattenLinkedList(head->next);
        head = merge(head, mergedHead);
        return head;
    }
};