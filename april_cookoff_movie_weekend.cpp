#include<iostream>
using namespace std;
int main(){
    int t, n, i, num, max, pos;
    cin>>t;
    while(t--){
        cin>>n;
        int l[n], r[n];
        for(i=0; i<n; i++){
            cin>>l[i];
        }
        for(i=0; i<n; i++){
            cin>>r[i];
        }
        max = 0;
        for(i=0; i<n; i++){
            num = l[i]*r[i];
            if(num>max){
                max = num;
                pos = i;
            }
            else if(num == max){
                if(r[pos] < r[i]){
                    max = num;
                    pos = i;
                }
            }
        }
        cout<<pos+1<<"\n";
    }
}