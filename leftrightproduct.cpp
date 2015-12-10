#include<iostream>

using namespace std;

int main(){


	int a[] = {1,2,3,4};
	int n = 4, i, j;
	int left[n], right[n];


	left[0] = 1;
	right[n-1] = 1;


	for(i=1;i<n;i++){

		j = n-i-1;

		left[i] = left[i-1]*a[i-1];
		right[j] = right[j+1]*a[j+1];

	}


	for(i=0;i<n;i++){

		cout<<a[i]<<"="<<left[i]*right[i]<<"\n";
	}



}