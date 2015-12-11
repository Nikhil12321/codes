#include<iostream>

using namespace std;


int main(){




	string s[100];


	string str;
	int pos = 0;
	int i;
	int countofwords = 0;
	getline(cin, str, '\n');
	int word = 0;




	for(i=0;i<str.size();i++){



		if(str.at(i)==' '){


			s[word++] = str.substr(pos, countofwords);
			pos = i+1;
		}

		else{

			countofwords++;
		}
	}


	string total;
	string temp;
	int left = 0;
	int right = word;

	while(left<=right){


		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;
		right--;
	}


	for(i = 0;i<word;i++){


		total+=s[i];
	}

	cout<<"\n"<<total;








}