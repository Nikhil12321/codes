//Print a tree in spiral level order

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct Node{

    int data;
    Node * left;
    Node * right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};



void inorder(Node * root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


Node * initTree(){

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

void printSpiral(Node * root){

    if(!root)
        return;
    Node * element;
    bool reverse = true;
    queue<Node *> q;
    stack<Node *> s;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        element = q.front();
        q.pop();
        if(element == 0){
            if(reverse){
                reverse = false;
                while(!s.empty()){
                    cout<<s.top()->data<<" ";
                    s.pop();
                }
                q.push(NULL);
            }
            else{
                reverse = true;
                if(q.empty())
                    break;
                else
                    q.push(NULL);
            }
        }
        else{
            if(reverse){
                s.push(element);
            }
            else
                cout<<element->data<<" ";
            if(element->left)
                q.push(element->left);
            if(element->right)
                q.push(element->right);
        }
    }
}

int main(){

    Node * root = initTree();
    printSpiral(root);
}