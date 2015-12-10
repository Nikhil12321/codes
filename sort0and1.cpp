#include<iostream>

using namespace std;

int main(){


	int a[]={1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};

	int n = sizeof(a)/sizeof(int);

	int ptr1=0,ptr2=1, temp;

	while(ptr2<n && ptr1<n){


		while(a[ptr1]==0 && ptr1<n)
			ptr1++;
		while(a[ptr2]==1 && ptr1<n)
			ptr2++;

		if(ptr2<n && ptr1<n){

			temp = a[ptr1];
			a[ptr1] = a[ptr2];
			a[ptr2] = temp;

		}
			
	}

	for(int i=0;i<n;i++)
		cout<<a[i];
}