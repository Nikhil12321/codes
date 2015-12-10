#include<iostream>
#include<bitset>
#include<climits>

using namespace std;


int main(){

	int x,y,n;

	cin>>x>>y>>n;

	bitset<32> a(x), b(y);
	bitset<32> temp;

	temp.reset();
	for(int i=n-1;i>=0;i--)
		temp.set(i);

	cout<<"\n"<<a;
	cout<<"\n"<<b;

	x=x>>n;
	x=x<<n;

	bitset<32> f(x), r;

	b = b&temp;

	r = f|b;


	cout<<"\n"<<r;



	






}