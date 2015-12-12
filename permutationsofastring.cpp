#include<iostream>
#include<string>

using namespace std;




void perm(string s, string res){


	if(s.size()==0)
	{
		cout<<res<<"\n";
		return;
	}


	string temp;
	string temp2;
	temp = s;
	temp2 = res;
	char a;

	for(int i = 0; i<temp.size();i++){


		s = temp;
		res = temp2;
		a = s[i];
		s.erase(i,1);
		res.push_back(a);
		perm(s, res);
	}
	return;

}

int main(){


	string s = "abcde";
	string res;
	perm(s, res);



}