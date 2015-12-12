#include<iostream>
#include<string.h>

using namespace std;


bool compare(char *reg, char *ex){



	int n = strlen(reg);
	int m = strlen(ex);
	int i=0, j=0;
	int flag = 1;
	char ch;

	while(i<n && j<m){




		if(reg[i+1]=='*'){


			//no comparison after .* is encountered
			
			if(reg[i]=='.')
				break;

			else{



				ch = reg[i];

				while(ex[j]==ch)
					j++;

				i = i+2;
			}
		}

		//if one to one matching is required

		else{


			while(reg[i+1]!='*' && i<n && j<m){


				if(reg[i]!=ex[j]){

					flag=0;
					break;
				}
				i++;
				j++;

			}
		}

		if(flag==0)
			break;
	}


	//any remaining expression

	if(i>=n && j<m && flag==1){


		flag=0;

	}

	//any remaining regex

	else if(i<n && j>=n && flag==1){

		while(i<n){

			if(reg[i+1]!='*'){

				flag=0;
				break;
			}
			i=i+2;
		}
	}

	if(flag==0)
		return false;
	else
		return true;



}


int main(){



	char reg[] = "a*ddb*";

	char ex[] = "aadbbbbb";


	cout<<compare(reg, ex);
}