/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head){
    /*
        For god's sake man, take care of the corner cases.
        One element, no element and only two elements
    */
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    ListNode * ptr = head;
    ListNode * ptrN = head->next;
    ListNode * prev;
    if(ptrN==0)
        return NULL;
    ptr->next = ptrN->next;
    ptrN->next = ptr;
    head = ptrN;
    /*
        Check for only two elements
    */
    if(ptr->next == 0)
        return head;
    /*
        Change the values to the starting values of the loop.
    */
    prev = ptr;
    ptr = ptr->next;
    ptrN = ptr->next;
    while(ptrN!=0){
        ptr->next = ptrN->next;
        ptrN->next = ptr;
        prev->next = ptrN;
        /*
            In case it becomes null, nothing more to do
        */
        if(ptr->next==NULL)
            return head;
        prev = ptr;
        ptr = ptr->next;
        ptrN = ptr->next;
    }
    return head;
}
};