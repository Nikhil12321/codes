#include<iostream>

using namespace std;


int max(int a, int b){


	return (a>b)?a:b;
}


int maxSquareMatrix(int **a, int m, int n){


	int y[] = {1, 1, 0};
    int x[] = {0, -1, -1};
	cout<<a[0+x[0]][0+y[0]];

}


int main(){


    int m, n, i, j, k;

    cin>>m>>n;

    int *a[m];


    


    for(i = 0; i<m; i++){

        a[i] = new int[n];

        for(j=0; j<n; j++){

            cin>>a[i][j];
        }
    }

    int ans = maxSquareMatrix(a, m, n);


}


