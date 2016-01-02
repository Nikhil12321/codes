#include<iostream>
#include<string>

using namespace std;


int min(int a, int b, int c){



    if(b<=a && b<=c)
        return b;
    if(a<=b && a<=c)
        return c;
    if(c<=a && c<=b)
        return c;
}



int editDistance(string &s1, string &s2){


    int n = s1.size();
    int m = s2.size();
    int i, j;
    int dp[n+1][m+1];



    for(i=0; i<=n; i++){


        for(j=0; j<=m; j++){

            if(i==0){
                dp[i][j] = i;
                continue;
            }

            if(j==0){
                dp[i][j] = j;
                continue;
            }

            if(s1[i-1] == s2[j-1]){

                dp[i][j] = dp[i-1][j-1];
            }
            else{

                dp[i][j] = 1+min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main(){




    string s1, s2;

    cin>>s1>>s2;

    int ans = editDistance(s1, s2);
    cout<<ans<<endl;
}