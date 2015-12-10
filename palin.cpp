#include<iostream>
#include<string>

using namespace std;


int main(){



	string s;
	int t;

	cin>>t;

	while(t--){


		cin>>s;
		string org_string;
		org_string=s;
		int len;
		len=s.length();

		int start, end, increased, temp;
		start=-1;
		end=len;
		increased=0;

		while(start<end){

			start++;
			end--;

			if(s.at(start)-'0'>s.at(end)-'0'){

				s.at(end)=s.at(start);
				increased=1;
				
				continue;
			}

			if(s.at(start)-'0'<s.at(end)-'0'){

				s.at(end)=s.at(start);
				increased=0;
			}
		}



		if(increased==0){

			if(len%2!=0){

				if(s.at(len/2)!='9'){

					temp=s.at(len/2)-'0';
					temp++;
					s.at(len/2)=temp;
				}
