#include<iostream>
using namespace std;

int main(){
	long long t, i, n, j, x, y, ans, N;
	N = 100000;
	cin>>t;
	long long a[N+1];
	for(i=0; i<=N; i++)
		a[i] = 0;
	for(i=1; i<=N; i+=2){
		for(j=i; j<=N; j+=i){
			a[j] += i;
		}
	}
	while(t--){
		cin>>x>>y;
		ans = 0;
		for(i=x; i<=y; i++){
			ans += a[i];
		}
		cout<<ans<<endl;
	}
}