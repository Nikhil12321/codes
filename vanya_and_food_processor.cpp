#include<iostream>
using namespace std;

#define ll long long int

int main(){
	ll i, n, h, k, inside, tim, x;
	cin>>n>>h>>k;
	ll a[n];
	tim = 0;
	inside = 0;
	for(i=0; i<n; i++){
		cin>>a[i];
		if(inside + a[i] <= h){
			inside += a[i];
		}
		else{
			tim += 1;
			inside = a[i];
		}
		tim += inside/k;
		inside = inside%k;
	}
	tim += inside/k;
	inside = inside%k;
	tim += (inside>0);
	
	cout<<tim<<endl;
}