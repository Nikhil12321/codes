#include<iostream>
#include<string>
#include<vector>



using namespace std;



void num(string so_far, int nu){



	if(nu<1){
		cout<<so_far<<"\n";
		return;
		}

	int i;

	int n = nu%10;
	string s[10];
	s[2] = "abc";
	s[3] = "def";
	s[4] = "ghi";
	s[5] = "jkl";
	s[6] = "mno";
	s[7] = "pqrs";
	s[8] = "tuv";
	s[9] = "wxyz";

	string temp = so_far;


	for(i=0;i<s[n].size();i++){

		so_far = temp;
		so_far.insert(so_far.begin(), s[n].at(i));
		num(so_far, nu/10);
	}
	return;


}

int main(){


	int n=645;
	string s;

	num(s, n);

}