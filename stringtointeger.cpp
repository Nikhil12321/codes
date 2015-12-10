#include<iostream>
#include<string>
#include<math.h>


using namespace std;


int convert(string str, int pos){


	int a;

	if(pos == str.size()-1){


		a = str.at(pos)-'0';
		return a;
	}

	a = str.at(pos)-'0';
	a = a*pow(10, str.size()-1-pos);

	return a+convert(str, pos+1);

}


int main(){



	string str;

	cin>>str;

	cout<<convert(str, 0);
}