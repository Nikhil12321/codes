#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::vector<int> a, b, ans;
    int carry = 0, i = 0;
    int ele;
    ListNode * prev;

    while(l1!=NULL){
        a.push_back(l1->val);
        l1 = l1->next;
    }
    while(l2!=NULL){
        b.push_back(l2->val);
        l2 = l2->next;
    }
    while(i<a.size() && i<b.size()){
        ele = (a[i]+b[i]+carry)%10;
        carry = (a[i]+b[i]+carry)/10;
        ans.push_back(ele);
        i++;
    }
    while(i<a.size()){
        ele = (a[i]+carry)%10;
        carry = (a[i]+carry)/10;
        ans.push_back(ele);
        i++;
    }
    while(i<b.size()){
        ele = (b[i]+carry)%10;
        carry = (b[i]+carry)/10;
        ans.push_back(ele);
        i++;
    }
    if(carry!=0){
        ans.push_back(carry);
    }
    ListNode * s = new ListNode(ans[0]);
    prev = s;
    i=1;
    while(i<ans.size()){
        ListNode * temp = new ListNode(ans[i]);
        prev->next = temp;
        prev = temp;
        i++;
    }
    return s;
    }

 }

int main(){

    ListNode * start = new ListNode(2);
    start->next = new ListNode(4);
    start->next->next = new ListNode(3);
    ListNode * start2 = new ListNode(5);
    start2->next = new ListNode(6);
    start2->next->next = new ListNode(4);
    ListNode * ans = addTwoNumbers(start, start2);
    ListNode * ptr = ans;
    while(ptr){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }


}

//https://leetcode.com/problems/add-two-numbers/