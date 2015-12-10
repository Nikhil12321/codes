#include<iostream>


using namespace std;


int main(){


	int temp;
	string s;
	s="12321";
	temp=s.at(2)-'0';
	temp++;
	s.at(2)=temp;
	cout<<s;
}
	
