#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
bool checkUnique(string &s){
    unordered_set<char> m;
    for (int i = 0; i <s.size(); ++i)
    {
        if(m.find(s[i])!=m.end())
            return false;
        else
            m.insert(s[i]);
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    cout<<checkUnique(s);
}