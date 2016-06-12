// Print all root to leaf paths
#include<iostream>
#include<vector>

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

void printVector(vector<int> &v){

	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
void rootToLeafPaths(vector<int> &path, Node * node){
	path.push_back(node->data);
	if(!node->left && !node->right){
		printVector(path);
		path.pop_back();
		return;
	}
	if(node->left)
		rootToLeafPaths(path, node->left);
	if(node->right)
		rootToLeafPaths(path, node->right);
	path.pop_back();
}

int main(){

	Node * root = initTree();
	std::vector<int> v;
	rootToLeafPaths(v, root);
}
