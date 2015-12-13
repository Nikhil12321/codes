#include<iostream>


using namespace std;




bool queen(int **m, int posx, int n){




	if(posx>=n)
		return true;



	int x[] = {1,1,0,-1,-1,-1,0,1};
	int y[] = {0,-1,-1,-1,0,1,1,1};

	int flag=0, w, q, k, i;


	for(i = 0; i<n; i++){



		flag=1;
		k = 0;

		while(k<8){


			w = i;
			q = posx;

			while(q+x[k]>=0 && w+y[k]>=0 && q+x[k]<n && w+y[k]<n){


				if(m[q+x[k]][w+y[k]]==1){

					flag = 0;
					break;
				}

				q = q+x[k];
				w = w+y[k];

			}
			if(flag==0)
				break;

			k++;
		}

		if(flag==1){

			m[posx][i] = 1;
			int temp = posx+1;
			if(queen(m, temp, n)==true){

				
				return true;
			}
			else{
				m[posx][i] = 0;
				flag=0;
				}

		}
	}

	if(flag==0)
		return false;
}


int main(){

	int n = 8;
	int *m[n];


	for(int i = 0;i<n;i++)
		m[i] = new int[n];


	for(int i=0;i<n;i++){


		for(int j = 0;j<n;j++)
			m[i][j]=0;

	}

	if(queen(m, 0, n)==true)
	{
		for(int i=0;i<n;i++){


				for(int j = 0;j<n;j++){

					cout<<m[i][j]<<" ";
				}
				cout<<"\n";
			}

	}
	else{
		cout<<"no solution exists";
	}
}