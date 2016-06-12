#include<iostream>
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
    root->left->left->right = new Node(8);
    root->left->left->right->left = new Node(9);
    root->left->right = new Node(5);
    root->left->right->right = new Node(10);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}


int diameter(Node * root){

    pair<int, int> ans = getDiameter(root);
    return ans.first;

}

pair<int, int> getDiameter(Node * root){
    pair<int, int> ans(0, 0);
    return ans;

}

int main(){

    Node * root = initTree();
    cout<<diameter(root);

}