#include<iostream>
#include<string>
using namespace std;


int maxi(int a, int b){
    if(a>b)
        return a;
    return b;
}

int longestPalindrome(string str) {

    int l, i, j, n;
    n = str.size();
    bool ans[n][n];
    int prod, maxprod=-111;
    int maxl=1, posl=0;
    int max=-111;

    for(i=0; i<=n; i++){
        ans[i][i] = true;
        ans[i][0] = false;
    }

    for(l=2; l<=n; l++){
        i=0;
        while((i+l)<=n){
            j = i+l-1;
            if(str[i]==str[j]){
                if(ans[i+1][j-1]){

                    ans[i][j] = true;
                    if(max < l){
                        max = l;
                        posl = i;
                        maxl = l;
                    }
                }
                else
                    ans[i][j] = false;
            }
            else
                ans[i][j] = false;
            i=j;
        }
    }

    
    cout<<str.substr(posl, maxl);
    return 0;
}

int main(){

    string s;
    cin>>s;
    int ans = longestPalindrome(s);
    cout<<ans<<endl;
}