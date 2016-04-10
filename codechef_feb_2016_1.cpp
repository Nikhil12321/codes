#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    long n, i, a;
    unordered_set<long> s;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>a;
        s.insert(a);
    }
    for(i=0; i<n; i++){
        if(s.find(i+1)==s.end())
            cout<<i+1<<" ";
    }
}
//https://www.codechef.com/FEB16/problems/CHEFDETE