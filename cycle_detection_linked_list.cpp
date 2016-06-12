//cycle detection in a Linked List
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void createCircular(Node * root){

    Node * temp = new Node(2);
    Node * temp1 = new Node(3);
    Node * temp2 = new Node(4);
    Node * temp3 = new Node(5);
    Node * temp4 = new Node(6);
    Node * temp5 = new Node(7);
    Node * temp6 = new Node(8);
    Node * temp7 = new Node(9);
    root->next = temp;
    temp->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = temp5;
    temp5->next = temp6;
    temp6->next = temp1;
       
}


void detectCycle(Node * start){

    bool flag = false;
    if(!start)
        cout<<"No cycle";
    Node * slow = start;
    Node * fast = start;
    if(slow->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    else{
        cout<<"No cycle";
        return;
    }
    while(fast != 0){
        if(slow == fast){
            flag = true;
            cout<<"Cycle Detected at "<<slow->data<<endl;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if(!flag){
        cout<<"No cylce";
        return;
    }
    slow = start;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;

    }
    cout<<"beginning of the cycle is at "<<slow->data<<endl;
} 




int main(){
    Node * head = new Node(1);
    createCircular(head);
    detectCycle(head);
}