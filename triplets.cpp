#include<iostream>
#include<stdlib.h>


using namespace std;

int compare(const void *a, const void *b){


	return (*(int*)a - *(int*)b);

}


int main(){


	int i, num, j, left, right, sum;
	int a[] = {-1, 2, 3, -2, 5, -3, 4, -4};

	qsort(a, 8, sizeof(int), compare);
	int n = 8;

	for(i=0; i<8; i++){


		num = a[i];
		left = i+1;
		right = n-1;

		while(left<right){


			sum = a[left]+a[right]+num;

			if(sum==0){

				cout<<num<<" "<<a[left]<<" "<<a[right]<<"\n";
				left++;
				right--;
			}
			else if(sum>0)
				right--;
			else
				left++;
		}
	}
}