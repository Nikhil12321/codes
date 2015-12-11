#include<iostream>


using namespace std;

int main(){



	int i,mid,front,rear,k;

	int a[][4] = {{2,8,10,14},{3,9,11,17},{7,11,15,20},{9,16,21,25}};
	int n=4;
	cin>>k;

	for(i=0 ;i<n; i++){



		if(a[i][0]<=k && a[i][n-1]>=k){

			front = 0;
			rear = n-1;

			while(front <= rear){


				mid = (front+rear)/2;
				

				if(a[i][mid]==k){
					cout<<"found at "<<i<<" "<<mid;
					break;
				}
				else if(a[i][mid] < k)
					front = mid+1;
				else
					rear = mid-1;
			}
		}
	}
}