#include<iostream>
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

	int a = 1123;
	cout<<itoa(a, 10);
}