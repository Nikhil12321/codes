#include<iostream>
#include<stack>

using namespace std;


stack<char> reverse(stack<char> s){


    stack<char> temp;

    int count;
    char d, c;


    while(!s.empty()){


        c = s.top();
        s.pop();

        while(!temp.empty()){


            d = temp.top();
            temp.pop();
            s.push(d);
            count++;
        }

        temp.push(c);

        while(count>0){

            d = s.top();
            s.pop();
            temp.push(d);
            count--;
        }
    }

    while(!temp.empty()){


        c = temp.top();
        temp.pop();
        s.push(c);

    }

    return s;
}



int main(){



    stack<char> s;
    char ch = 'a';

    for(int i=0; i<10; i++)
        s.push(ch++);

    while(!s.empty()){

        cout<<s.top();
        s.pop();

    }6

    cout<<endl;

    ch = 'a';

     for(int i=0; i<10; i++)
        s.push(ch++);


    stack<char> ans = reverse(s);

    while(!ans.empty()){

        cout<<ans.top();
        ans.pop();

    }



}