#include <iostream>
#include <climits>
using namespace std;

void segregate(long long int a[], long long int n){
	
	long long int start, end;
	
	start = 0;
	end = n-1;
	while(start < end){
		
		while(start < end && a[start]%2 == 0)
			start++;
		while(start < end && a[end]%2 != 0)
			end--;
		if(start < end){
			
			long long int temp = a[start];
			a[start] = a[end];
			a[end] = temp;
			//really important to increment these and if we do not it,
			//the next iteration will not run since the starting conditions 
			//of the while loops will not be satisfied in the initial case
			//itself.
			start++;
			end--;
		}
		
		
	}
	return;
}

int main() {
	long long int t, i, x, n;
	cin>>t;
	while(t--){
	    cin>>n;
		long long int a[n];
		for(i=0; i<n; i++)
		    cin>>a[i];
		segregate(a,n);
	    cout<<endl;
	}
	return 0;
}