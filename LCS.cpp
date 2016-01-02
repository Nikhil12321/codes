#include<iostream>
#include<string>

using namespace std;


int max(int &a, int &b){

    return (a>b)?a:b;
}




int LCS(string &s1, string &s2){


    int n, m, flag = 0;
    n = s1.size();
    m = s2.size();
    int i, j, mx;

    int ans[n][m];


    for(i=0; i<n; i++)
        for(j=0; j<m ;j++)
            ans[i][j] = 0;


    for(i=0; i<n; i++){

        for(j=0; j<m; j++){

            cout<<ans[i][j]<<" ";
        }

        cout<<endl;
    }

    cout<<endl;


    for(i=0; i<n; i++){

        if(flag == 1){
            ans[i][0] = 1;
            continue;
        }

        if(s1[0] == s2[i]){

            ans[i][0]++;
            flag=1;
        }
    }

    flag=0;

    for(i=0; i<m; i++){

        if(flag == 1){
            ans[0][i] = 1;
            continue;
        }

        if(s2[0] == s1[i]){

            ans[0][i]++;
            flag=1;
        }
    }



    for(i=1; i<n; i++){

        for(j=1; j<m; j++){


            if(s1[i] == s2[j])
                ans[i][j] = 1+ans[i-1][j-1];
            else
                ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
        }
    }


    for(i=0; i<n; i++){

        for(j=0; j<m; j++){

            cout<<ans[i][j]<<" ";
        }

        cout<<endl;
    }

    cout<<endl;

    return ans[n-1][m-1];


    




    
}

int main(){


    string s1, s2;

    cin>>s1;
    cin>>s2;

    int ans = LCS(s1, s2);

    cout<<ans<<endl;


}

