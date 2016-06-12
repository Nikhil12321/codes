//Adding Linked Lists
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

void createLists(Node * head1, Node * head2){


    head1->next = new Node(1);
    head1->next->next = new Node(6);
    head2->next = new Node(9);
    head2->next->next = new Node(2);
       
}

Node * addLists(Node * start1, Node * start2){

    int digit, sum1, x, sum2, total_sum;
    Node * temp;
    Node * save;
    digit = 1;
    sum1 = sum2 = 0;
    temp = start1;
    while(temp != 0){

        x = (temp->data) * digit;
        sum1 += x;
        digit *= 10;
        temp = temp->next;
    }
    digit = 1;
    sum2 = 0;
    temp = start2;
    while(temp != 0){
        x = (temp->data)*digit;
        sum2 += x;
        digit *= 10;
        temp = temp->next;
    }

    total_sum = sum1 + sum2;
    digit = 10;
    x = total_sum%10;
    Node * t = new Node(x);
    save = t;
    t->next = NULL;
    total_sum /= 10;
    digit = 10*digit;
    while(total_sum > 0){
        x = total_sum%10;
        temp = new Node(x);
        temp->next = save;
        save = temp;
        total_sum /= 10;

    }
    return save;
}

void printList(Node * head) {
    while (head) {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main(){
    
    Node * head1 = new Node(7);
    Node * head2 = new Node(5);
    createLists(head1, head2);
    printList(addLists(head1, head2));

}