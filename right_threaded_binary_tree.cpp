#include<iostream>
using namespace std;

struct node{

    int data;
    node* left;
    node* right;
    bool thread;

};

node * addNode(int data){

    node * temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->thread = false;
    return temp;
}

void makeThread(node *&root, node *parent){

    if(root->left)
        makeThread(root->left, root);
    if(root->right)
        makeThread(root->right, parent);
    else if(!root->right){
        root->right = parent;
        root->thread = true;
    }
}

void edit(node *&root){

    node * temp = new node;
    temp->left = root;
    temp->right = NULL;
    root = temp;
}

void reverse(node * root){

    node * temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void inorder(node * root){
    if(root==NULL)
        return;
    if(root->left)
        inorder(root->left);
    cout<<root->data<<" ";
    if(root->right)
        inorder(root->right);
    return;
}


node * leftmost(node * root){
    if(root==NULL)
        return NULL;
    if(root->left==NULL)
        return root;
    return leftmost(root->left);
}
void traverseThreaded(node * root){

    root = leftmost(root);
    while(root){
        cout<<root->data<<" ";
        if(root->thread)
            root = root->right;
        else
            root = leftmost(root->right);
    }
}

int main(){

    node * root = addNode(6);
    root->left = addNode(3);
    root->right = addNode(8);
    root->left->left = addNode(1);
    root->left->right = addNode(5);
    root->right->left = addNode(7);
    root->right->right = addNode(11);
    root->right->right->right = addNode(13);
    root->right->right->left = addNode(9);
    makeThread(root, NULL);
    traverseThreaded(root);
    
}