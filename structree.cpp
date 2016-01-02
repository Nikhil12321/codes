#include<iostream>


using namespace std;


struct BinaryTree{


    int data;
    BinaryTree * left;
    BinaryTree * right;

};



BinaryTree * createBinaryTree(){

    BinaryTree * root = new BinaryTree();
    int data;
    cout<<"enter data"<<endl;
    cin>>data;
    root->data = data;
    cout<<"left for"<<data<<"?(Y/N)"<<endl;
    char ch;
    cin>>ch;
    if(ch == 'y'){

        root->left = createBinaryTree();
    }
    else{
        root->left = 0;
    }
    cout<<"right for"<<data<<"?(Y/N)"<<endl;
    cin>>ch;
    if(ch == 'y'){

        root->right = createBinaryTree();
    }
    else{
        root->right = 0;
    }

    return root;

}


void printInorder(BinaryTree * root){

    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
    return;
}


int main(){


    BinaryTree *a;
    a = createBinaryTree();



}