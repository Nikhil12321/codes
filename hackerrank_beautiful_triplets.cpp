#include<iostream>
using namespace std;

int main(){

	int i, j, n, d, count, pos;
	cin>>n>>d;
	int a[n], neighbour[n];

	for(i=0; i<n; i++){
		cin>>a[i];
		neighbour[i] = -1;
		for(j = i-1; j>=0; j--){
			if(a[i] - a[j] == d){
				neighbour[i] = j;
				break;
			}
		}
	}
	count = 0;
	for(i=n-1; i>=0; i--){

		if(neighbour[i] != -1){
			pos = neighbour[i];
			if(neighbour[pos] != -1){
				count++;
			}
		}
	}
	cout<<count;
}