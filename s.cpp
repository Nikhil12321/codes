#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main(){
	


	string s = "abc"
	string s1 = "def";
	string s2 = "ghi";

	vector<string> v1;
	vector<string> v2;

	v1.push_back(s);
	v2.push_back(s1);
	v2+=v1;
	cout<<v2[1];

}