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




int main() {
    int N,data;
    cin >> N;
    Node * head = NULL;
    for (int i = 0; i < N; i++) {
        cin >> data;
        insertElementAtHead(head, data);
    }

    printList(head);

    reverse(head);

    printList(head);
}