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
//point the threads of the threaded binary tree
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
    //if no right subtree then mark it as a successor to a previous node
    else if(!root->right)
        root->thread = succ;
    return;
}
//random function to see whether the thing works
void edit(node *&root){

    node * temp = new node;
    temp->left = root;
    temp->right = NULL;
    root = temp;
}
//reverse left and right subtrees
void reverse(node * root){

    node * temp = root->left;
    root->left = root->right;
    root->right = temp;
}
//inroder traversal
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
//find the leftmost element of a tree/subtree.
//to find the inorder successor of an element root, call this function with leftmost(root->right)
node * leftmost(node * root){
    if(root==NULL)
        return NULL;
    if(root->left==NULL)
        return root;
    return leftmost(root->left);
}
//to print the threaded binary tree (inorder, duh). We only need the first element of the seq. Rest are marked
//by the threads
void printThreaded(node * root){

    node * temp = leftmost(root);

    while(temp!=NULL){

        cout<<temp->data<<" ";
        temp = temp->thread;
    }
}
//Just reverse the left and right subtrees of each node
void mirror(node *&root){

    if(root->left)
        mirror(root->left);
    if(root->right)
        mirror(root->right);
    //remember to take care of the cases where there is only one subtree
    if(root->left && !root->right)
    {
        root->right = root->left;
        root->left = NULL;
    }
    //taking care of only right subtree case
    if(root->right && !root->left)
    {
        root->left = root->right;
        root->right = NULL;
    }
    //both subtrees present
    else{

        node * temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    return;
       
}

//function that finds and returns the nodes if found in case of lca
//everything recieved by reference since elements not changed and memory is conserved
//Can be used in cases if it is not known if one element is present or not
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
//flags get true if corresponding elements are found
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