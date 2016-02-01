#include<iostream>
#include<climits>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode():val(0), next(NULL){}
      ListNode(int x) : val(x), next(NULL) {}
  };
int removeNode(ListNode * head, int n, ListNode * parent){

    if(head->next == NULL){
        /*
            if last has to removed
            */
        if(n==1){
            parent->next=NULL;
            return INT_MIN;
        }
        return 2;
    }
    int temp = removeNode(head->next, n, head);
    if(temp == n){
        if(parent==NULL)
            return -2;
        parent->next = head->next;
        return INT_MIN;
    }
    else{
        return ++temp;
    }
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    /*
        Reeaaaaaaaaaaaaaaaaaaaallllllllly important corner case
        */
    if(head->next == NULL && n>0)
        return NULL;
    int ans = removeNode(head, n, NULL);
    if(ans == -2)
        head = head->next;
    return head;
}
void printList(ListNode * head){

    while(head!=NULL){
        cout<<head->val;
        head = head->next;
    }
}
int main(){
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    removeNthFromEnd(head, 4);
    printList(head);
       
}
