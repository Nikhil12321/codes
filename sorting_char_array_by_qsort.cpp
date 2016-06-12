/*
* Determine if all characters are unique in a string
*/

#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int comp(const void *a, const void *b){

	return (*(char*)a - *(char*)b);
}


int main(){

	char str[] = "abcde";
	qsort(str, strlen(str), sizeof(char), comp);
	for(int i=0; i<strlen(str); i++){

		if(str[i] == ' ')
			continue;
		if(str[i] == str[i+1]){
			cout<<"No";
			break;
		}

	}
	cout<<"Yes";
}