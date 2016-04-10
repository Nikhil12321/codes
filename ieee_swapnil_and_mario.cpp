#include<iostream>
#include<climits>
using namespace std;

long long int func(long long int a, long long int b){
    long long int x, y;
    long long int c;
    x = a*a;
    y = b*b;
    c = 2*a*b;
    long long int ans;
    ans = x + y - c;
    return ans;
}

int main(){

    long long int t, n, i, j, minx;
    long long int x;

    cin>>t;

    while(t--){
        cin>>n;
        long long int a[n];
        long long int min[n];

        for(i=0; i<n; i++)
            cin>>a[i];

        min[0] = 0;

        for(i=1; i<n; i++){

            minx = INT_MAX;
            for(j = i-1; j>=0; j--){

                x = func(a[i], a[j]) + min[j];
                if(x < minx){
                    minx = x;
                }
            }
            min[i] = minx;
        }
        cout<<min[n-1]<<"\n";
    }
}

//Just 60/100 passed