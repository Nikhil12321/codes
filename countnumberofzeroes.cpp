#include<iostream>

using namespace std;


int count(int n){


	if(n<1)
		return 0;

	int a = n%10;

	if(a==0)
		return count(n/10)+1;
	else
		return count(n/10);
}

int main(){


	int n;
	cin>>n;
	cout<<"\n"<<count(n);


}