#include<iostream>

using namespace std;

int main(){


	int a[][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};

	int startr=0;
	int startc=0;
	int r = 4;
	int c = 5;
	int row = 4;
	int col = 5;
	int i,j;



	while(startr<row/2 && startc<col/2){



		for(i=startc; i<c-1; i++){


			cout<<a[startr][i]<<" ";

		}

		for(i=startr; i<r-1; i++){


			cout<<a[i][c-1]<<" ";

		}

		for(i=c-1; i>startc; i--){


			cout<<a[r-1][i]<<" ";

		}

		for(i=r-1; i>startr; i--){


			cout<<a[i][startc]<<" ";

		}

		startr++;
		startc++;
		r--;
		c--;


	}




}