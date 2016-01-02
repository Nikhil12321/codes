#include<iostream>

using namespace std;


int min(int &a, int &b)
{

    return (a>b)?b:a;
}


//Can be done better by storing K in a 2d matrix or in the same matrix at the position of the element itself

int maxSquareMatrix(int **a, int m, int n){

    int i, j, k, q, newx, newy, savex, savey, savek;

    int y[] = {1, 1, 0};
    int x[] = {0, 1, 1};

    bool ans[m][n][min(m,n)];


    for (i = 0; i < m; i++)
    {
        for(j=0; j<n; j++){

            if(a[i][j] == 1)
                ans[i][j][0] = true;

            else
                ans[i][j][0] = false;
            }
        }

    

    for(k=1; k<=min(m, n); k++){

        
        for (i = 0; i < m; i++){
            
            for(j=0; j<n; j++){

                ans[i][j][k] = true;

                if(ans[i][j][k-1] == true){

                    for(q=0; q<3; q++){

                        newx = i+x[q];
                        newy = j+y[q];

                        if(newx<0 || newx>=m || newy<0 || newy>=n || (ans[newx][newy][k-1] == false)){
                            ans[i][j][k] = false;
                            break;
                        }
                    }
                }
                else
                    ans[i][j][k] = false;

                if(ans[i][j][k] == true){
                    //cout<<i<<" "<<j<<" "<<k<<endl;
                    savex = i;
                    savey = j;
                    savek = k;
                }
            }

        }       
    }

    cout<<savex<<" "<<savey<<" "<<savek<<endl;

}




/* Sample input: only 1's and 0's


6 5
0 1 1 0 1
0 1 0 1 0
0 1 0 1 0
1 1 1 1 0
1 1 1 1 1
0 0 0 0 0

*/

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