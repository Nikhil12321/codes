#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

int main(){

    int t, i, n;
    string a;
    int count;
    
    cin>>t;

    while(t--){

        cin>>n;
        count = 0;
        unordered_set<string> s;
        for(i=0; i<n; i++){
            cin>>a;
            if(s.find(a) != s.end())
                count++;
            else
                s.insert(a);
        }
        cout<<count<<"\n";
    }
}