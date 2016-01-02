#include<iostream>


template<typename T>
class BinaryTreeNode{

    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

public:

    BinaryTreeNode(){}

    T &getdata(){

        return data;
    }

    template<typename U>
    friend class BinaryTree;

};




template<typename T>
class BinaryTree{

    BinaryTreeNode<T> *root;



    BinaryTreeNode<T> * createTree(BinaryTreeNode<T> * head){


        
    }
    

public:

    void makeTree(){

        root = createTree(root);
    }


}