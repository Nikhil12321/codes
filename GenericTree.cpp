#include<iostream>
#include<queue>
#include<vector>
#include<stack>


using namespace std;

template<typename T>
class GenericTreeNode{

    T data;
    vector<GenericTreeNode* > children;

public:

    GenericTreeNode(){}

    T &getdata(){

        return data;
    }

    template<typename U>
    friend class GenericTree;

};


template<typename T>
class GenericTree{


    GenericTreeNode<T> *root;

    static GenericTreeNode<T> * createRecursive(){

        GenericTreeNode<T> *node = new GenericTreeNode<T>;
        T d;

        cout<<"enter node data"<<endl;
        cin>>d;
        node->data = d;
        cout<<"enter number of children"<<endl;
        int n;
        cin>>n;

        for(int i=0;i<n;i++){

            GenericTreeNode<T> * temp = createRecursive();
            node->children.push_back(temp);
        }

        return node;
    }

    static GenericTreeNode<T> * createIterative(){


        stack<GenericTreeNode<T> * > q;

        GenericTreeNode<T> * head = new GenericTreeNode<T>;
        q.push(head);
        int n;


        while(!q.empty()){


            GenericTreeNode<T> * k = q.top();
            q.pop();
            cout<<"Enter data"<<endl;
            cin>>k->data;
            cout<<"Enter number of children"<<endl;
            cin>>n;
            for(int i=0;i<n;i++){

                GenericTreeNode<T> * temp = new GenericTreeNode<T>;
                q.push(temp);
                k->children.push_back(temp);
            }
        }

        return head;

    }

    
    static void printRecursive(const GenericTreeNode<T> *curr){

        if (!curr) return;
        cout<<curr->data<<" ";
        for(int i=0; i<curr->children.size(); i++){
            printRecursive(curr->children[i]);
        }
        return;
    }

    static GenericTreeNode<T> * findLargest(GenericTreeNode<T> * node){


        GenericTreeNode<T> * max = node;

        for(int i=0; i<node->children.size(); i++){


            GenericTreeNode<T> * t = findLargest(node->children[i]);

            if(t->data > max->data){
                max = t;
            }
        }

        return max;

    }

    static int countHeight(GenericTreeNode<T> * curr){


        GenericTreeNode<T> * temp = curr;
        GenericTreeNode<T> * end = new GenericTreeNode<T>;
        int height = 0;
        queue<GenericTreeNode<T> * > q;
        q.push(temp);
        q.push(end);

        while(!q.empty()){


            GenericTreeNode<T> * t = q.front();
            q.pop();

            if(t == end){

                if(q.empty())
                    break;
                q.push(end);
                height++;
            }
            for(int i = 0; i<t->children.size(); i++){

                q.push(t->children[i]);
            }
        }
        return height;

    }

    static bool compare(GenericTreeNode<T> * root1, GenericTreeNode<T> * root2){


        if(!root1 && !root2)
            return true;

        else if(!root1 || !root2)
            return false;

        if(root2->data != root1->data)
            return false;

        if(root1->children.size() != root2->children.size())
            return false;

        for(int i=0; i<root1->children.size(); i++)
        {

            if(!compare(root1->children[i], root2->children[i]))
                return false;

        }

        return true;


    }


    static int countLeaf(GenericTreeNode<T> * curr){


        if(!curr)
            return 0;

        if(curr->children.size() == 0){
            cout<<curr->data<<endl;
            return 1;
        }

        int count = 0;

        for(int i=0; i<curr->children.size(); i++){

            count+=countLeaf(curr->children[i]);
        }

        return count;
    }


    static void printzigzag(GenericTreeNode<T> * head){

        stack<GenericTreeNode<T> * > s;
        bool flag = false;
        queue<GenericTreeNode<T> * > q;

        GenericTreeNode<T> * end = new GenericTreeNode<T>;

        q.push(head);
        q.push(end);

        while(!q.empty()){


            GenericTreeNode<T> * temp = q.front();
            q.pop();
            //cout<<"got "<<temp->data<<endl;

            if(temp == end){

             

                if(q.empty()){

                    while(!s.empty()){
                        cout<<s.top()->data<<" ";
                        s.pop();
                    }
                    break;
                }

                else{


                    if(flag==true){

                        flag = false;
                        
                        cout<<endl;

                        while(!s.empty()){
                            cout<<s.top()->data<<" ";
                            s.pop();
                        }
                        cout<<endl;
                    }
                    else{

                        flag = true;
                    }
                    //cout<<"pushed null after "<<q.back()->data<<endl;
                    q.push(end);
                    
                }
            }

            else{

                for(int i=0; i<temp->children.size(); i++){

                    //cout<<"added "<<temp->children[i]->data<<" to the queue "<<endl;
                    q.push(temp->children[i]);
                }

                if(flag == true)
                    s.push(temp);
                else
                    cout<<temp->data<<" ";
            }
        }
    }

public:

    void create(){

        root = createRecursive();
        //root = createIterative();
    }

    void printIt(){

        cout<<"Preorder travelsal is ";
        printRecursive(root);
        cout<<endl;
    }

    int getHeight(){

        return countHeight(root);
    }

    GenericTreeNode<T> * findNodeWithLarestData(){

        return findLargest(root);
    }

    int countLeafNodes(){

        return countLeaf(root);
    }

    void zigzag(){

        printzigzag(root);
        return;
    }

    bool operator==(GenericTree<T> tree2){

        return compare(root, tree2.root);
    }

    

};


int main(){


    GenericTree<int> root, root2;
    root.create();
    root.printIt();
    cout<<"The height of tree is "<<root.getHeight()<<endl;
    GenericTreeNode<int> *a = root.findNodeWithLarestData();
    cout<<"largest data of tree is "<<a->getdata()<<endl;
    cout<<"number of leaf nodes are "<<root.countLeafNodes()<<endl;
    cout<<endl;
    root.zigzag();



}
