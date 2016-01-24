#include<iostream>
#include<vector>

using namespace std;

void printLeaders(std::vector<int> v){

    int n = v.size();
    int max = v[n-1];
    cout<<max<<" ";
    for (int i = n-2; i >=0; i--)
    {
        if(v[i]>max){
            max = v[i];
            cout<<max<<" ";
        }
    }
}
int main(){

    int n,a;
    std::vector<int> v;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    printLeaders(v);
}