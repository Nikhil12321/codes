#include<iostream>
#include<climits>
using namespace std;

int min(int a, int b){
	return (a>b)?b:a;
}

int main(){

	int n, i, a;
	cin>>n;
	int ans[n];
	ans[0] = 0;
	cin>>a;
	for(i=1; i<n; i++){
		cin>>a;
		if(a == 1)
			ans[i] = INT_MAX;
		else{
			if(i==1)
				ans[i] = 1;
			else
				ans[i] = min(ans[i-1], ans[i-2]) + 1;
		}
	}
	cout<<ans[n-1];
}

// https://www.hackerrank.com/contests/world-codesprint-april/challenges/jumping-on-the-clouds