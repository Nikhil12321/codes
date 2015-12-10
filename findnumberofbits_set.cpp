#include<iostream>
#include<bitset>

using namespace std;


int main(){



	int a,b,c, count=0;

	cin>>a;

	bitset<32> x(a), y(b);

	b=1;

	cout<<x<<"\n"<<y<<"\n";

	for(int i=0;i<32;i++){


		c = a&b;
		if(c==1)
			count++;

		a = a>>1;

	}

	cout<<"\n"<<count;
}