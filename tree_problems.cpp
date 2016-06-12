#include<iostream>
#include<climits>
using namespace std;

struct node{

    int data;
    node* left;
    node* right;
    node * thread;
};

int max(int a, int b){
    return (a>b)?a:b;
}

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
//transform tree such that data of a node is the sum of its left subtree+root->data
int leftSum(node *&root){
    int lsum = 0;
    int rsum = 0;
    if(root->left)
        lsum = leftSum(root->left);
    if(root->right)
        rsum = leftSum(root->right);
    root->data = lsum + root->data;
    //we return adding the right sum too because we need the sum of the whole
    //left subtree in the parent node
    return root->data + rsum;
}

//first element in pair represents the max sum which can be continued upwards if going upwards can create the max sum
//the second element of the pair is the overall maximum sum of the entire tree below
pair<int, int> maxPathSumHelper(node * root){
    if((!root->left) && (!root->right)){
        pair<int, int> p(root->data, root->data);
        return p;
    }

    pair<int, int> pLeft(INT_MIN, INT_MIN);
    pair<int, int> pRight(INT_MIN, INT_MIN);
    if(root->left)
        pLeft = maxPathSumHelper(root->left);
    if(root->right)
        pRight = maxPathSumHelper(root->right);

    //m is the max of the overall maximums of left and right
    int m = max(pLeft.second, pRight.second);

    if(pLeft.first==INT_MIN)
        pLeft.first = 0;
    if(pRight.first==INT_MIN)
        pRight.first = 0;

    pair<int, int> ans;
    //K is the sum of present element plus the sum of continuing left and right max sums
    int k = pLeft.first + pRight.first + root->data;
    //q is the maximum amongst the continued left and right trees
    int q = max(pLeft.first, pRight.first);
    //q is the sum of either left or right (whichever is max) and the present data to be sent above as the continuing max
    q = q + root->data;
    //if the sum formed by including the left, right and present continuing tree
    //is greater than the left/right overall maximum, then overall maximum is left, right and present continuing sum sent above
    if(k>m){

        ans.first = q;
        ans.second = k;
        return ans;
    }
    //else overall maximum remains the same (left or right whichever is max)
    else{
        ans.first = q;
        ans.second = m;
        return ans;
    }

}
//maximum path sum of a tree
int maxPathSum(node * root){

    pair<int, int> p = maxPathSumHelper(root);
    return p.second;
}


//Find the diameter of a tree which is the longest path from any node to
//any node in a tree. This is a helper function of the function below.
//The pairs represent the following:
//:::First element of the pair represents the ongoing length of the longest path
//:::The second element represents the maximum path found beneath or of the node
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
    
    // start of second part calc
    // We add two and not 1 because both edges of the node have to be added
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
    
    node * root = addNode(6);
    root->left = addNode(3);
    root->right = addNode(8);
    root->left->left = addNode(1);
    root->left->right = addNode(5);
    node * b = root->right->left = addNode(7);
    root->right->right = addNode(11);
    root->right->right->right = addNode(13);
    node * a = root->right->right->left = addNode(9);    
    cout<<maxPathSum(root);    
}