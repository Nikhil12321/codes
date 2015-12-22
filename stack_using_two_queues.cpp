#include<iostream>
#include<queue>

using namespace std;

class Stack{

    queue<char> q1;
    queue<char> q2;


public:

    void push(char ch){


        q1.push(ch);
    }


    char pop(){

        char ch;

        if(q1.size() == 0)
            return 0;

        while(q1.size() != 1){


            ch = q1.front();
            q2.push(ch);
            q1.pop();

        }
        ch = q1.front();
        q1.pop();
        q1.swap(q2);
        return ch;

    }


};



int main(){


    Stack s;
    for(char i='a'; i<='z'; i++)
        s.push(i);

    char ch = s.pop();
    while(ch != 0){

        cout<<ch<<" ";
        ch = s.pop();
    }

    cout<<endl;
}