#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<vector<string> > v;
    vector<string> v1;
    v1.push_back("11");
    v1.push_back("12");
    vector<string> v2;
    v2.push_back("21");
    v2.push_back("22");
    v.push_back(v1);
    v.push_back(v2);
    /*
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
    }
    */
    cout<<v[1][0][1];
}