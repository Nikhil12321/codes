#ifndef GENERIC_TREE_H
#define GENERIC_TREE_H
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
template<typename T>
class GenericTreeNode {
    T data;
    vector<GenericTreeNode *> children;
    public:
    GenericTreeNode() {}
    GenericTreeNode(const T & d) : data(d) {}
    const T & getData() const {
        return data;
    }
    T & getData() {
        return data;
    }
    template <typename V>
    friend class GenericTree;
};
template<typename T>
class GenericTree {
    GenericTreeNode<T> * root;
    static GenericTreeNode<T> * copyas(const GenericTreeNode<T> * otherroot) {
        if (!otherroot) return NULL;
        GenericTreeNode<T> * newnode = new GenericTreeNode<T>;
        newnode->data = otherroot->data;
        for (int i=0; i < otherroot->children.size(); i++) {
            GenericTreeNode<T> * child = copyas(otherroot->children[i]);
            newnode->children.push_back(child);
        }
        return newnode;
    }
    static void clearRecursive(GenericTreeNode<T> * current) {
        if (!current) return;
        for (int i=0; i < current->children.size(); i++) {
            clearRecursive(current->children[i]);
        }
        delete current;
    }
    static GenericTreeNode<T> * createRecursive() {
        GenericTreeNode<T> * node = new GenericTreeNode<T>;
        cout << "Enter Data ";
        cin >> node->data;
        cout << "Enter number of children";
        int count;
        cin >> count;
        for (int i = 0; i < count; i++) {
            GenericTreeNode<T> * child = createRecursive();
            node->children.push_back(child);
        }
        return node;
    }
    static pair<const GenericTreeNode<T> *, const GenericTreeNode<T> *> findSecondLargestRecursive(
            const GenericTreeNode<T> * curr) {
        pair<const GenericTreeNode<T> *, const GenericTreeNode<T> *> ans, childans;
        ans.first = curr;
        ans.second = NULL;
        for (int i = 0; i < curr->children.size(); i++) {
            childans = findSecondLargestRecursive(curr->children[i]);
            if (childans.first->data > ans.first->data) {
                ans.second = ans.first;
                ans.first = childans.first;
                if (childans.second && childans.second->data > ans.second->data) {
                    ans.second = childans.second;
                }
            } else {
                if (!ans.second) {
                    ans.second = childans.first;
                } else if (childans.first->data > ans.second->data) {
                    ans.second = childans.first;
                }
            }
        }
        return ans;
    }
    static void printAllRootToPathRecursive(const GenericTreeNode<T> *curr, vector<const GenericTreeNode<T> *> & V) {
        if (!curr) return;
        V.push_back(curr);
        if (curr->children.size() == 0) {
            for (int i =0;  i < V.size(); i++) {
                cout << V[i]->data << " ";
            }
            cout << endl;
            V.pop_back();
            return;
        }
        for (int i = 0; i < curr->children.size(); i++) {
            printAllRootToPathRecursive(curr->children[i], V);
        }
        V.pop_back();
    }
    public:
    GenericTree() : root(0) {}
    GenericTree(const GenericTree & T1) : root(0) {
        root = copyas(T1.root);
    }
    ~GenericTree() {
        clearRecursive(root);
        root = NULL;
    }
    void clear() {
        clearRecursive();
        root = NULL;
    }
    GenericTree & operator=(const GenericTree & T1) {
        clear();
        root = copyas(T1.root);
        return *this;
    }
    void createTree() {
        if (root) {
            throw "Tree already created";
        }
        root = createRecursive();
        return;
    }
    void printLevelOrder() const {
        if (!root) return;
        queue<const GenericTreeNode<T> *> Q;
        Q.push(root);
        while (!Q.empty()) {
            const GenericTreeNode<T> * current = Q.front();
            Q.pop();
            cout << current->data << " ";
            for (int i = 0; i < current->children.size(); i++) {
                Q.push(current->children[i]);
            }
        }
    }
    const GenericTreeNode<T> * secondLargest() const {
        if (!root || root->children.size() == 0) return NULL;
        pair<const GenericTreeNode<T> *, const GenericTreeNode<T> *> ans;
        ans = findSecondLargestRecursive(root);
        return ans.second;
    }
    void printAllRootToPath() const {
        vector<const GenericTreeNode<T> * > V;
        printAllRootToPathRecursive(root, V);
        return;
    }
};
#endif
