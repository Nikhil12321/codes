#include<iostream>
#include<string>

using namespace std;


int main(){



	char str[] = "This is a test";
	string s(str);

	int a = s.find("iss")==string::npos;

	cout<<a;

	
}