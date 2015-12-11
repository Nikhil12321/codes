#include<iostream>

using namespace std;


int paths(int m[][3], int x, int y, int k, int l){



	if(x==k-1 && y==l-1)
		return 1;
	if(x>k-1 || y>l-1)
		return 0;



	return paths(m, x+1, y, k, l)+paths(m, x, y+1, k, l);

}

int main(){




	int a[][3] = {{0,0,0},{0,0}};

	cout<<paths(a,0,0,2,3);
}



