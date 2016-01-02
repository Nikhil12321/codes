#include<iostream>
#include<stack>

using namespace std;



string absolutePath(string path){

    stack<string> s;
    int i, j;


    i = 0;

    if(path.size() == 1)
        return path;

    if(path[0] != '/')
        path.insert(path.begin(), '/');


    while(i < path.size()){


        j = i+1;

        while(path[j] != '/' && j<path.size()){


            j++;
        }

        string sub = path.substr(i+1, j-i-1);

        if(sub.size()>0){  //not like '//'

            if(sub == ".."){

                for(int k = 0; k<2 && !s.empty(); k++){

                s.pop();
            
            }
            }

            else if(sub != "."){

                s.push(sub);
                s.push("/");
            }
        }

        if(j>i)
            i = j;
        else
            i++;
    }

    //remove any trailing /
    if(s.size()>1){
        while(s.top() == "/" && !s.size()>1)
            s.pop();
    }   

    stack<string> temp;


    //reverse the stack 

    while(!s.empty()){


        temp.push(s.top());
        s.pop();
    }

    string ss;

    //make a string out of the reversed

    while(!temp.empty()){
        ss+=temp.top();
        temp.pop();
    }

    //insert a leading / if absent

    if(ss[0] != '/');
        ss.insert(ss.begin(), '/');

    //remove trailing again
    if(ss.size()>1){

        int x = ss.size()-1;

        while(ss[x] == '/' && ss.size()!=1)
            ss.pop_back();
    }


    return ss;

}

int main(){

    string s;
    cin>>s;
    string d = absolutePath(s);
    cout<<d<<endl;

    
}

//https://leetcode.com/problems/simplify-path/