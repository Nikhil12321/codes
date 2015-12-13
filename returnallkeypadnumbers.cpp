#include<iostream>
#include<string>
#include<vector>



using namespace std;



vector<string> num(string so_far, int nu, vector<string> v){



	if(nu<1){

		vector<string> x;
		x.push_back(so_far);
		//cout<<so_far<<"\n";
		return x;
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
	vector<string> x;
	vector<string> y;

	for(i=0;i<s[n].size();i++){

		so_far = temp;
		so_far.insert(so_far.begin(), s[n].at(i));
		x = num(so_far, nu/10, x);
		v.insert(v.end(), x.begin(), x.end());
		x.clear();
	}
	return v;


}

int main(){


	int n=645;
	string s;
	vector<string> v;
	vector<string> v1;
	v1 = num(s, n, v);
	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<"\n";
}