#include<iostream>
using namespace std;

struct node{

    int data;
    node* left;
    node* right;
    node * thread;
};

node * addNode(int data){

    node * temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->thread = NULL;
    return temp;
}

void makeThread(node *&root, node *pred, node *succ){

    if(!root->left && !root->right){
        if(pred!=NULL)
            pred->thread = root;
        root->thread = succ;
        return;
    }
    if(root->left)
        makeThread(root->left, pred, root);
    if(root->right)
        makeThread(root->right, root, succ);
    else if(!root->right)
        root->thread = succ;
    return;
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

void printThreaded(node * root){

    node * temp = leftmost(root);

    while(temp!=NULL){

        cout<<temp->data<<" ";
        temp = temp->thread;
    }
}

void mirror(node *&root){

    if(root->left)
        mirror(root->left);
    if(root->right)
        mirror(root->right);
    if(root->left && !root->right)
    {
        root->right = root->left;
        root->left = NULL;
    }
    if(root->right && !root->left)
    {
        root->left = root->right;
        root->right = NULL;
    }
    else{

        node * temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return;
       
}

node * lcaHelper(node *&node1, node *&node2, bool &flag1, bool &flag2, node *&root){

    if(!root)
        return NULL;
    if(root == node1){
        flag1 = true;
        if(flag2){
            return root;
        }
        else{
            if(root->left)
                lcaHelper(node1, node2, flag1, flag2, root->left);
            if(root->right)
                lcaHelper(node1, node2, flag1, flag2, root->right);
            return root;
        }
    }
    if(root == node2){
        flag2 = true;
        if(flag1){
            return root;
        }
        else{
            if(root->left)
                lcaHelper(node1, node2, flag1, flag2, root->left);
            if(root->right)
                lcaHelper(node1, node2, flag1, flag2, root->right);
            return root;
        }
    }
    node * l;
    node * r;

    if(root->left){
        l = lcaHelper(node1, node2, flag1, flag2, root->left);
    }
    else
        l = NULL;
    if(root->right){
        r = lcaHelper(node1, node2, flag1, flag2, root->right);
    }
    else
        r = NULL;
    if(l && r){
        return root;
    }
    else if(l)
        return l;
    return r;
}

node * lca(node * root, node * node1, node * node2){

    bool flag1 = false;
    bool flag2 = false;
    node * temp = lcaHelper(node1, node2, flag1, flag2, root);
    if(temp && flag1 && flag2)
        return temp;
    else
        return NULL;
}


int main(){

    node * root = addNode(6);
    root->left = addNode(3);
    root->right = addNode(8);
    root->left->left = addNode(1);
    root->left->right = addNode(5);
    node * b = root->right->left = addNode(7);
    root->right->right = addNode(11);
    root->right->right->right = addNode(13);
    node * a = root->right->right->left = addNode(9);
    node * l = lca(root, a, b);
    if(l!=NULL)
        cout<<l->data;
    else
        cout<<"NULL";

}