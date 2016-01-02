#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
template <typename T>
class BinaryTreeNode {
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    public:
    BinaryTreeNode(): left(NULL), right(NULL){}
    BinaryTreeNode(const T & d) : data(d) , left(NULL), right(NULL){}
    const T & getData() const {
        return data;
    }

    template<typename V>
        friend class BinaryTree;
};
template<typename T>
class BinaryTree {
    BinaryTreeNode<T> * root;
    static BinaryTreeNode<T> * copyas(const BinaryTreeNode<T> * fromroot) {
        if (!fromroot) return NULL;
        BinaryTreeNode<T> * root = new BinaryTreeNode<T>(fromroot->data);
        root->left = copyas(fromroot->left);
        root->right = copyas(fromroot->right);
        return root;
    }
    public:
    BinaryTree() : root(NULL) {}
    ~BinaryTree() { clear(); }
    BinaryTree(const BinaryTree<T> & T1): root(0) {
        root = copyas(T1.root);
    }
    BinaryTree & operator=(const BinaryTree & T1) {
        clear();
        root = copyas(T1.root);
        return *this;
    }
    bool isEmpty() const { return root == NULL; }

    void clear() {
        clearHelper(root);
        root = NULL;
    }
    void printPreOrder() const {
        printPreOrderHelper(root);
        cout << endl;
        return;
    }
    void printPostOrder() const {
        printPostOrderHelper(root);
        cout << endl;
        return;
    }
    void printInOrder() const {
        printInOrderHelper(root);
        cout << endl;
        return;
    }
    int height() const {
        return heightHelper(root);
    }
    bool operator==(const BinaryTree<T> & T1) const {
        return compare(root, T1.root);
    }
    void printAllRootToLeafPaths() const {
        vector<T> V;
        printAllRootToLeafPathsHelper(root, V);
        return;
    }
    bool checkSumChildren() const {
        return checkSumChildrenHelper(root);
    }
    void postOrderIterative() const {
        if (!root) return;
        stack<pair<const BinaryTreeNode<T>*, bool> > S;
        pair<const BinaryTreeNode<T>*, bool> P(root, 0), temp;
        S.push(P);
        while (!S.empty()) {
            P = S.top();
            if (P.second == true) {
                cout << P.first->data << " ";
                S.pop();
                continue;
            }
            S.top().second = true;
            if (P.first->right) {
                temp.first = P.first->right;
                temp.second = 0;
                S.push(temp);
            }
            if (P.first->left) {
                temp.first = P.first->left;
                temp.second = 0;
                S.push(temp);
            }
        }

    }
    void createRecursive() {
        if (root) {
            throw " Tree already exists";
        }
        root = createRecursiveHelper();
    }
    void deleteHalfNodes() {
        root = deleteHalfNodesHelper(root);
    }

    private:

    
    static BinaryTreeNode<T> * createRecursiveHelper() {
        T el;
        char ch;
        cout << "Enter Data";
        cin >> el;
        BinaryTreeNode<T> * root = new BinaryTreeNode<T>(el);
        cout << el <<" Has Left (y/n): ";
        cin >> ch;
        if (ch == 'Y' || ch == 'y') {
            root->left = createRecursiveHelper();
        }
        cout << el <<" Has right (y/n): ";
        cin >> ch;
        if (ch == 'Y' || ch == 'y') {
            root->right = createRecursiveHelper();
        }
        return root;
    }
    static BinaryTreeNode<T> * deleteHalfNodesHelper(BinaryTreeNode<T> *root) {
        if (!root->left && !root->right) {
            return root;
        }
        if (root->left && root->right) {
            root->left = deleteHalfNodesHelper(root->left);
            root->right = deleteHalfNodesHelper(root->right);
            return root;
        }
        BinaryTreeNode<T> * temp = root->left ? root->left : root->right;
        delete root;
        return deleteHalfNodesHelper(temp);
    }
    static bool checkSumChildrenHelper(const BinaryTreeNode<T> *root) {
        if (!root || (!root->left && !root->right)) {
            return true;
        }
        T ld = root->left ? root->left->data : 0 ;
        T rd = root->right ? root->right->data : 0;
        if (root->data != ld + rd) {
            return false;
        }
        return checkSumChildrenHelper(root->left) && checkSumChildrenHelper(root->right);
    }
    static void printAllRootToLeafPathsHelper(const BinaryTreeNode<T> *root, vector<T> & V) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            for(int i = 0; i < V.size(); i++) {
                cout << V[i] << " ";
            }
            cout << root->data << endl;
            return;
        }
        V.push_back(root->data);
        printAllRootToLeafPathsHelper(root->left, V);
        printAllRootToLeafPathsHelper(root->right, V);
        V.pop_back();
        return;
    }
    static bool compare(const BinaryTreeNode<T> *root, const BinaryTreeNode<T> *fromroot) {
        if ((root && !fromroot) || (!root && fromroot)) {
            return false;
        }
        if (!root && !fromroot) {
            return true;
        }
        if (root->data != fromroot->data) {
            return false;
        }
        return compare(root->left, fromroot->left) && compare(root->right, fromroot->right);

    }
    static int heightHelper(const BinaryTreeNode<T> * root) {
        if (root == NULL) {
            return 0;
        }
        return max(heightHelper(root->left), heightHelper(root->right)) + 1;
    }
    static void printPreOrderHelper(const BinaryTreeNode<T> * root) {
        if (!root) return;
        cout << root->data << " ";
        printPreOrderHelper(root->left);
        printPreOrderHelper(root->right);
    }
    static void printPostOrderHelper(const BinaryTreeNode<T> * root) {
        if (!root) return;
        printPostOrderHelper(root->left);
        printPostOrderHelper(root->right);
        cout << root->data << " ";
    }
    static void printInOrderHelper(const BinaryTreeNode<T> * root) {
        if (!root) return;
        printInOrderHelper(root->left);
        cout << root->data << " ";
        printInOrderHelper(root->right);
    }
    static void clearHelper(BinaryTreeNode<T> * root) {
        if (root == NULL) return;
        clearHelper(root->left);
        clearHelper(root->right);
        delete root;
        return;
    }
};
#endif
