#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n, i, x, j;
    cin>>n;
    bool prime[n+1];
    int roo = ssqrt(n);
    for(i=0; i<=n; i++)
        prime[i] = true;
    for(i=2; i<=roo; i++){
        j = 2;
        for(j=i; j<=roo; j+=i){
            prime[j] = false;
        }
    }
    for(i=2; i<=n; i++){
        if(prime[i])
            cout<<i<<" ";
    }
}