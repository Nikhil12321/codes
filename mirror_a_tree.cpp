// Mirror a tree
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

Node * mirror(Node * node1){
	Node * node2 = new Node(node1->data);
	Node * temp1;
	Node * temp2;
	if(node1->left){
		temp1 = mirror(node1->left);
	}
	else{
		temp1 = NULL;
	}
	if(node1->right)
		temp2 = mirror(node1->right);
	else
		temp2 = NULL;
	node2->left = temp2;
	node2->right = temp1;
	return node2;
}

void inorder(Node * root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node * root){
	if(root == 0)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);

}


int main(){

	Node * root = initTree();
	Node * root1 = mirror(root);
	inorder(root);
	cout<<endl;
	inorder(root1);
	cout<<endl;
	preorder(root1);

}
