#include<iostream>

using namespace std;



int expfunc(int a, int n){


	int c;

	if(n==1)
		return a;


	if(n%2!=0){

		n--;
		c = expfunc(a, n/2);
		return a*c*c;
	}


	c = expfunc(a, n/2);

	return c*c;
}




int main(){


	int a,n;

	cin>>a>>n;

	cout<<expfunc(a,n);

}