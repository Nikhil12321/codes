#include<iostream>
#include<string>


using namespace std;


int main(){



	int t;
	string s;
	char charray[100];
	cin>>t;

	while(t--){


		cin>>s;
		int stringcounter=0;
		int opcounter=0;
		int counter=0;
		while(counter<=s.length()-1){


			if(s.at(counter)>='a'&&s.at(counter)<='z'){

				cout<<s.at(counter);
				}
			else if(s.at(counter)==')'){

				cout<<charray[--opcounter];
			}

			else if(s.at(counter)=='('){
				counter++;
				continue;
			}
			else{

				charray[opcounter++]=s.at(counter);
			}
			counter++;
			}
		cout<<"\n";
			
	}
}
