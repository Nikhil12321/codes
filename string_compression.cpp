// String Compression

#include<iostream>
#include<string.h>
#include<string>
using namespace std;


char * reverse(char * str, int len){

	int i = 0;
	int j = len-1;
	while(i < j){
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}

}
char * itoa(int num, int base){

	int i=0, len = 0;
	int temp = num;
	while(temp > 0){
		len++;
		temp = temp/base;
	}
	char * str = new char[len+1];
	if(num == 0){
		str[i++] = '0';
	}
	while(num > 0){
		int x = num%base;
		str[i++] = (x>'9')?(x-10)+'a':x+'0';
		num = num/base;
	}
	str[i++] = '\0';
	reverse(str, i-1);
	return str;
}

int main(){
	string compressed = "";
	char saved;
	int count, no_of_added, i, len;
	char str[] = "aaaaaaaaaabbbbbbbbbbbbbbbbbb";
	saved = str[0];
	count = 1;
	no_of_added = 2;
	len = strlen(str);
	for(i=1; i<len; i++){
		if(saved == str[i]){
			count++;
		}
		else{
			compressed += saved;
			compressed += itoa(count, 10);
			saved = str[i];
			count = 1;
			no_of_added += 2;
		}
	}
	compressed += saved;
	compressed += itoa(count, 10);
	no_of_added += 2;

	if(no_of_added > len)
		cout<<"Original is smaller";
	else
		cout<<compressed<<endl;
}