#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
/*
    Check using stack if a string is balanced or not
*/
bool check(string s){
    stack<char> k;
    int i=0;
    while(i<s.size()){
        if(s[i] == '(')
            k.push(s[i]);
        else{
            if(k.empty())
                break;
            else
                k.pop();
        }
        i++;
    }
    /*
        Really important. Empty and no remaining elements
        Since we can exit with remaining elements
    */
    if(k.empty() && i==s.size())
        return true;
    return false;
}
void makeParanthesis(vector<string> &v, string s, int open, int close){
    if(open==0 && close==0){
        if(check(s))
            v.push_back(s);
        return;
    }
    if(open>0)
        makeParanthesis(v, s+'(', open-1, close);
    if(close>0)
        makeParanthesis(v, s+')', open, close-1);
}
vector<string> generateParenthesis(int n){
    vector<string> ans;
    string s = "";
    makeParanthesis(ans, s, n, n);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<string> ans = generateParenthesis(n);
    for (int i = 0; i < ans.size(); ++i)
    {           
        cout<<ans[i]<<endl;
    }
}