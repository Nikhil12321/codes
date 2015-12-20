#include<iostream>
using namespace std;
struct Node {
    int data;
    Node * next;
};


void insertElementAtHead(Node * &head, int data) {
    Node * curr = new Node;
    curr->data = data;
    curr->next = NULL;
    if (head == NULL) {
        head = curr;
        return;
    }
    curr->next = head;
    head = curr;
    return;
}
void printList(Node * head) {
    while (head) {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void insort(Node *&head){



    if(!head || !head->next)
        return;

    Node *in = head->next;
    Node *out = head;
    Node *prev = head;
    Node *par = 0;
    Node *save;



    while(in){

        par = 0;
        out = head;

        while(out->data < in->data && out != in){


            par = out;
            out = out->next;

        }

        save = in;

        if(par == 0){

            prev->next = prev->next->next;
            save->next = head;
            head = save;
            in = prev->next;

        }

        else if(in == out){

            prev = in;
            in = in->next;

        }

        else{

            prev->next = prev->next->next;
            par->next = save;
            save->next = out;
            in = prev->next;
        }





    }
}




int main() {
    int N,data;
    cin >> N;
    Node * head = NULL;
    for (int i = 0; i < N; i++) {
        cin >> data;
        insertElementAtHead(head, data);
    }

    printList(head);


    insort(head);

    printList(head);
}