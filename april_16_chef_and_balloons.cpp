#include<iostream>
using namespace std;

int main(){

    long long int  t, i, sum, k;
    long long int a[3];

    cin>>t;
    while(t--){
        for(i=0; i<3; i++){
            cin>>a[i];
        }
        cin>>k;
        sum = 0;
        for(i=0; i<3; i++){
            if(k-1 > a[i])
                sum += a[i];
            else
                sum += k-1;
        }
        cout<<++sum<<"\n";
    }
}