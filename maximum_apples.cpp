#include<iostream>

using namespace std;


int max(int a, int b){

    if(a>b)
        return a;
    return b;
}


int maxApples(int **a, int n, int m){


    int temp[n][m];

    int i, j;

    for(int i=0;i<n;i++){

        for(int j=0; j<m; j++){


            temp[i][j] = 0;
        }
    }

    temp[0][0] = a[0][0];

    for(int i=1;i<n;i++){

        temp[0][i] = temp[0][i-1] + a[0][i];
    }

    for(int j=1; j<m; j++){

        temp[j][0] = temp[j-1][0] + a[j][0];
    }


    for(int i=1;i<n;i++){

        for(int j=1; j<m; j++){

            temp[i][j] = max(temp[i-1][j], temp[i][j-1]) + a[i][j];
            
        }
    }

    return temp[n-1][m-1];





}



int main(){

    int n, m;
    cin>>n>>m;

    int *a[n];

    for(int i=0;i<n;i++){

        a[i] = new int[m];

        for(int j=0; j<m; j++){

            cin>>a[i][j];
        }
    }
    cout<<endl;

    int ans = maxApples(a, n, m);
    cout<<ans<<endl;

}