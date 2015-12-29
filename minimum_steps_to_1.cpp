#include<iostream>
#include<climits>

using namespace std;


int min(int a, int b){


    if(a>b)
        return b;
    return a;


}

int main(){



    int n, i, a, b, c, x;

    int t;
    cin>>t;
    while(t--){
        cin>>n;

        int ans[n+1];
        ans[1] = 0;

        for(i = 2; i<=n; i++){

            //b = INT_MAX;
            //c = INT_MAX;

            ans[i] = ans[i-1]+1;

            if(i%2 == 0)
                ans[i] = min(ans[i/2]+1, ans[i]);
            if(i%3 == 0)
                ans[i] = min(ans[i/3]+1, ans[i]);

            

        }

        cout<<ans[n];
}
}