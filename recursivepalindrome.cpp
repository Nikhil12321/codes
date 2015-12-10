#include<iostream>
#include<string>

using namespace std;


bool palin(char *str, int left, int right){



	if(left==right)
		return true;
	if(left==right-1){


		if(str[left]==str[right]){

			return true;
		}		
		else
			return false;
	}
	if(str[left]==str[right]){
		return palin(str, left+1, right-1);
	}

	else
		return false;
}




int main(){



	char str[100];
	cin>>str;
	int size=0;
	
	for(int i = 0;str[i]!='\0';i++)
		size++;

	cout<<palin(str, 0, size-1);
}