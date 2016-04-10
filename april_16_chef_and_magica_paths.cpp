#include<iostream>
using namespace std;

int main(){
    long long int t, m, n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        if((m == 1 && n==2 ) || (m==2 && n==1)){
            cout<<"Yes"<<"\n";
            continue;
        }
        else if(m>1 && n>1 && (n%2==0 || m%2==0)){
            cout<<"Yes"<<"\n";
            continue;
        }
        else
            cout<<"No"<<"\n";
    }
}