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
    root->left->right->right->right = new Node(11);
    root->left->right->right->right->left = new Node(12);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}


int max(int a, int b, int c){

    if(a>b){
        if(c>a)
            return c;
        return a;
    }
    if(b>a){
        if(c>b)
            return c;
        return b;
    }
}
pair<int, int> getDiameter(Node * root){
    pair<int, int> ans(0, 0);
    pair<int, int> leftAns;
    pair<int, int> rightAns;
    
    if(!root)return ans;
    if(!root->left && !root->right)
        return make_pair<int, int>(0, 0);
    if(root->left)
        leftAns = getDiameter(root->left);
    else
        leftAns = make_pair<int, int>(0, 0);
    if(root->right)
        rightAns = getDiameter(root->right);
    else
        rightAns = make_pair<int, int>(0, 0);
    if(leftAns.first > rightAns.first){
        ans.first = leftAns.first + 1;
    }
    else
        ans.first = rightAns.first + 1;
    
    //start of second part calc
    int diameter;
    if(leftAns.first == 0)
        diameter = leftAns.first + rightAns.first + 1;
    else if(rightAns.first == 0)
        diameter = leftAns.first + rightAns.first + 1;
    else
        diameter = leftAns.first + rightAns.first + 2;
    ans.second = max(diameter, leftAns.second, rightAns.second);
    cout<<"values at "<<root->data<<" are "<<ans.first<<" "<<ans.second<<endl;
    return ans;

}

int diameter(Node * root){

    pair<int, int> ans = getDiameter(root);
    return ans.second;

}



int main(){

    Node * root = initTree();
    inorder(root);
    cout<<diameter(root);
}