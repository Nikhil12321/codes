#include<iostream>

using namespace std;


int **func(int **a){

	a[1][1]++;
	return a;


}


int main(){

	

	int *a[2];

	for(int i=0;i<2;i++)
		a[i] = new int[2];

	for(int i=0;i<2;i++){

		for(int j=0;j<2;j++)
			a[i][j]=i+j;
	}
	func(a);

	cout<<a[1][1];


}