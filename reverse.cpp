#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t, x, n, k, pos;
    cin>>t;
    while(t--){
        
        cin>>n>>k;
        if(n%2==0){
            
            x = n/2;
            if(k < x)
                pos = 1+k*2;
            else
                pos = (n-k-1)*2;
        }
        else{
            
            x = n/2;
            if(k < x){
                pos = 1+k*2;
            }
            else if(k > x){
                pos = (n-1-k)*2;
            }
            else
                pos = n-1;
        }
        cout<<pos<<endl;
    }
    return 0;
}
