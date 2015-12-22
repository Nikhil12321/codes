#include<iostream>
#include<stack>
#include<vector>

using namespace std;



bool pushPopSequence(vector<int> &push, vector<int> &pop){


    std::vector<int>::iterator push_it = push.begin();
    std::vector<int>::iterator pop_it = pop.begin();

    stack<int> s;

    s.push(*push_it);

    push_it++;
    while(pop_it != pop.end()){


        if( !s.empty()){

            if(s.top() == *pop_it){

                s.pop();
                pop_it++;
                continue;
            }
        }

        if(push_it == push.end()){
            break;
        }
        s.push(*push_it);
        push_it++;
    }

    if(s.empty()){
        return true;
    }
    else{

        return false;    
    }
    
}


int main(){


    std::vector<int> v1;
    std::vector<int> v2;
    int n, i, a;

    cin>>n;

    for (int i = 0; i < n; ++i)
    {   
        cin>>a;
        v1.push_back(a);
    }

    for (int i = 0; i < n; ++i)
    {   
        cin>>a;
        v2.push_back(a);
    }

    bool ans;

    ans = pushPopSequence(v1, v2);

    if(ans == true)
        cout<<"yes";
    else
        cout<<"no";


    
}