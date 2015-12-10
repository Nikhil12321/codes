#include<iostream>
#include<limits.h>

using namespace std;


int main(){



	int i,t,n;

	cin>>t;

	while(t--){


		cin>>n;
		int a[n];

		for(i=0;i<n;i++){
			cin>>a[i];
			}
		int max=INT_MIN;
		int profit=0;

		for(i=n-1;i>-1;i--){


			if(a[i]>=max)
				max=a[i];
			else{

				profit+=max-a[i];
				}
			}

		cout<<profit<<"\n";
	}
}
