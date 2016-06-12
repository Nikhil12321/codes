#include<iostream>
using namespace std;

int main(){

	// Constant pointer Cannot point to anything else
	int v = 4;
	int *const ptr1 = &v;
	cout<<*ptr1;


	int a = 5;
	// pointer to constant. Cannot change the value its pointing to
	const int *ptr = &a;
	cout<<*ptr;


}