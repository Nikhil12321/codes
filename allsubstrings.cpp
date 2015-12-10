#include<iostream>
#include<string>

using namespace std;

int main(){


	string str;
	int l,i;

	cin>>str;

	for(l=1;l<=str.size();l++){


		for(i=0;i+l<str.size();i++){

			cout<<str.substr(i,l)<<"\n";
		}
	}
}