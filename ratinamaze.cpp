#include<iostream>

using namespace std;


bool rat(int **m, int i, int j, int q, int w, int a, int b){




	if( (i>=q) || (j>=w) || (i<0) || (j<0) || (m[i][j]==-1) || (m[i][j]==1))
		return false;

	if(i==a && j==b){
		
		cout<<i<<" "<<j<<"\n";
		return true;
	}


	int x[] = {1,1,0,-1,-1,-1,0,1};
	int y[] = {0,-1,-1,-1,0,1,1,1};


	m[i][j]=-1;


	int k=0;

	while(k<8){




		if(rat(m, i+x[k], j+y[k], q, w, a, b)){

			cout<<i<<" "<<j<<"\n";
			return true;
		}

		k++;
	}
	return false;
}



int main(){

	int *a[3];

	for(int i = 0;i<5;i++){


		a[i] = new int[3];
	}

	a[0][0] = 0;
	a[0][1] = 1;
	a[0][2] = 1;
	a[1][0] = 0;
	a[1][1] = 1;
	a[1][2] = 1;
	a[2][0] = 1;
	a[2][1] = 0;
	a[2][1] = 0;

	rat(a, 0, 0, 3, 3, 2, 2);


}