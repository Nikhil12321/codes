#include<iostream>
#include<limits.h>

using namespace std;


int min(int *d, int n, int N, int count, int till_now){




	if(till_now==N)
		return count;

	if(till_now>N)
		return INT_MAX;

	int minimum = INT_MAX;


	for(int i=0;i<n;i++){


		int m = min(d, n, N, count+1, till_now+d[i]);

		if(m<minimum)
			minimum = m;
	}

	return minimum;
}


int main(){

	int d[] = {1,2,3,4};

	cout<<min(d, 4, 10, 0, 0);
}

