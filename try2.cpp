#include<iostream>
#include<string>
using namespace std;
int main(){
    string list = "a list of ";
    string s;
    getline(cin, s);
    /*if(s == list.substr(0, list.size()))
        cout<<true;
    else
        cout<<false;*/
    cout<<s.substr(0, list.size());
}