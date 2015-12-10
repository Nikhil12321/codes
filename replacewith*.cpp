#include<iostream>
#include<string>


using namespace std;



string convert(string str, int pos){

	string s;

	if(pos == str.size()-2){


		if(str[pos] == str[pos+1]){


			s+=str[pos];
			s+='*';
			s+=str[pos+1];

		}
		else{

			s+=str[pos];
			s+=str[pos+1];
		}

		return s;
	}


	if(str[pos]==str[pos+1]){


		s+=str[pos];
		s+='*';

	}
	else{



		s+=str[pos];

	}

	return s+convert(str, pos+1);
}


int main(){



	string s;

	cin>>s;

	cout<<convert(s, 0)<<"\n";

}