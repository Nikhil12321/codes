#include<iostream>
#include<vector>



using namespace std;


vector<int> merge(vector<int> &a, vector<int> &b, int i, int j){


	int n = a.size();
	int m = b.size();
	int element;

	std::vector<int> z;


	if(i<0 && j<0){

		vector<int> z;
		return z;
	}

	if((i>=0 && j<0)||(i>=0 && j>=0 && a[i]>b[j])){

		
		element = a[i];
		cout<<" from "<<a[i]<<" "<<b[j]<<" chose "<<element<<"\n";
		z = merge(a, b, i-1, j);
	}

	else{
		
		element = b[j];
		cout<<" from "<<a[i]<<" "<<b[j]<<" chose "<<element<<"\n";
		z = merge(a, b, i, j-1);

	}

	z.push_back(element);
	return z;
}



int main(){


	std::vector<int> v1;
	std::vector<int> v2;
	
	for(int i=1; i<10;i=i+2)
		v1.push_back(i);

	for(int i=2; i<=10;i=i+2)
		v2.push_back(i);
		

	vector<int> v3 = merge(v1, v2, v1.size()-1, v2.size()-1);

	for(int i=0;i<v3.size();i++)
		cout<<v3[i]<<" ";
}