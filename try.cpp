#include<iostream>

using namespace std;


int main(){





	int a[][4] = {{0,0,0,1},{0,1,0,0},{0,0,0,0},{0,0,1,0}};
	int n=4;
	int i,j,k,posx,posy,flag=1;
	int g,h;

	int y[] = {1,1,0,-1,-1,-1,0,1};
	int x[] = {0,-1,-1,-1,0,1,1,1};
	


	for(i=0;i<n;i++){


		for(j=0;j<n;j++){


			if(a[i][j]==1){

				cout<<"\n"<<"in at "<<i<<" "<<j;
				posx = i;
				posy = j;

				

				k=0;

				while(k<8){

					for(g=posx,h=posy;(g+x[k]>=0&&h+y[k]>=0&&g+x[k]<n&&h+y[k]<n)==1;){

						cout<<"g="<<g<<" "<<"h="<<h<<"\n";

						if(a[g+x[k]][h+y[k]]==1){

							flag=0;
							break;
						}

						g = g+x[k];
						h = h+y[k];
					}
					if(flag==0)
						break;
					k++;
				}

				if(flag==0)
					break;
			}

			if(flag==0)
				break;
		}

		if(flag==0)
			break;
	}

	if(flag==0)
		cout<<"nooo";
	else
		cout<<"yeaah";
	
}