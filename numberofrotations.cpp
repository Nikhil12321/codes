#include<iostream>

using namespace std;

int main(){



	int a[]={4,5,6,7,1,2,3};

	int n=7;

	int left, right, k, mid;

	left=0;
	right=n-1;

	while(left<=right){


		mid = (left+right)/2;
		cout<<"mid = "<<mid<<"\n";

		if(a[mid]<a[mid-1]){

			k=mid;
			break;
		}
		else if(a[mid]>a[mid+1]){

			k=mid+1;
			break;
		}
		else if(a[mid]<a[left])
			right=mid-1;
		else if(a[mid]>a[right])
			left=mid+1;


	}
	cout<<"rotation "<<k<<" times";
}