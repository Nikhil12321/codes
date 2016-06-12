// Determine if two trees are identical structurally
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

bool isIdentical(Node * root1, Node * root2){

	if(!root1 && !root2)
		return true;
	if((!root1 && root2) || (root1 && !root2))
		return false;
	if(root1->data == root2->data){

		bool leftAns = isIdentical(root1->left, root2->left);
		bool rightAns =  isIdentical(root1->right, root2->right);

		return (leftAns && rightAns);
	}
	else
		return false;
}


int main(){

	Node * root1 = initTree();
	Node * root2 = initTree();
	bool ans = isIdentical(root1, root2);
	cout<<ans;
}
