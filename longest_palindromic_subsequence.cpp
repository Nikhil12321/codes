#include<iostream>
#include<string>
using namespace std;


int maxi(int a, int b){
    if(a>b)
        return a;
    return b;
}

string longestPalindrome(string str) {

    int l, i, j, n;
    n = str.size();
    int ans[n][n];
    int max = -1111;
    int posl = 0;
    int maxl = 1;

    for(i=0; i<n; i++){
        ans[i][i] = 1;
        ans[i][0] = 0;
    }
    for(l=2; l<=n; l++){
        for(i=0; (l+i)<=n; i++){
            j = i+l-1;
            /*
            if(str[i]==str[j] && l==2){
                ans[i][j] = 2;
                if(max < ans[i][j]){
                    max = ans[i][j];
                    posl = i;
                    maxl = l;
                }
            }
            */
            if(str[i]==str[j]){
                ans[i][j] = ans[i+1][j-1]+2;
                if(max < ans[i][j]){
                    max = ans[i][j];
                    posl = i;
                    maxl = l;
                }
            }
            else
                ans[i][j] = maxi(ans[i][j-1], ans[i+1][j]);
        }
    }
    return str.substr(posl, maxl);
}

int main(){

    string s;
    cin>>s;
    string ans = longestPalindrome(s);
    cout<<ans<<endl;
}