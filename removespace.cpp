#include<iostream>
#include<string>

using namespace std;

void squeeze(char *str){

	int i=0;
	int j;
	
	while(str[i]!='\0'){


		if(str[i]==' '){

			j=i;
			cout<<j;
			while(str[j+1]!='\0'){

				cout<<str<<"\n";
				str[j]=str[j+1];
				j++;
			}
			str[j]='\0';

		}
	i++;
	}
	cout<<str;
}



int main(){




	char str[30];

	cin.getline(str, 30);
	squeeze(str);
}