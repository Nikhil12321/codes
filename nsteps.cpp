#include<iostream>

using namespace std;


int main(){



	int n=5;

	int l[n+1];

	int i, j;

	for(i=1;i<=n;i++)
		l[i]=0;

	l[n]=1;

	for(i=n-1;i>=1;i--){


		for(j=1;j<4;j++){

			if(i+j<=n){

				l[i]+=l[i+j];
			}
		}
	}

	cout<<l[1]<<"\n";


}