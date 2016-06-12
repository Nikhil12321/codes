#include<iostream>

using namespace std;

#define ll long long int

ll mod = 10000007;

ll pow(int a){
	if(a%2==0)
		return 1;
	return -1;
}

ll *factorial(ll n){

	ll *facs;
	facs = new ll[n+1];
	ll ans = 1;
	facs[0] = 1;

	for(ll i=1; i<=n; i++){
		ans = (i*ans)%mod;
		facs[i] = ans;
	}
	return facs;
} 


int main(){

	int t;
	ll i, n, sub1, sub2, fac_n;

	cin>>t;
	while(t--){
		sub1 = 0;
		cin>>n;
		ll *facs = factorial(n);
		fac_n = facs[n];
		for(i=0; i<=n; i++){
			// This is the primary derangement equation
			sub2 = ((fac_n/facs[i])*pow(i))%mod;
			sub1 += sub2;
		}
		cout<<sub1<<endl;
	}
}

// https://www.codechef.com/LOCAPR16/problems/VSQ2