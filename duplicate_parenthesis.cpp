#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool check(string str){


    stack<char> s;
    int i, flag = 0;

    i=0;

    while(i<str.size()){


        if(str[i] != ')'){

            flag = 0;
            s.push(str[i]);

        }

        else{

            while(s.top() != '('){

                flag = 0;
                s.pop();
            }

            s.pop();
            if(flag == 1){

                flag = 2;
                break;
            }
            else{

                flag = 1;
            }
        }
        i++;
    }

    if(flag == 2)
        return false;
    return true;
}



int main(){



    string s;
    cin>>s;

    cout<<check(s);
}