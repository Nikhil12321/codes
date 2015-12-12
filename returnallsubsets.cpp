#include<iostream>
#include<vector>


using namespace std;



vector<vector<int> > subsets(vector<int> &a, int pos){

	

	if(pos == a.size()){

		std::vector<int> v;
		vector<vector<int> > w;
		w.push_back(v);
		return w;


	}

	vector<vector<int> > temp = subsets(a, pos+1);
	int ss = temp.size();

	for(int i =0;i<ss;i++){

		std::vector<int> v = temp[i];
		v.push_back(a[pos]);
		temp.push_back(v);

	}

	return temp;




}

int main(){


	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<vector<int> > a = subsets(v, 0);

	for(int i =0 ;i<a.size();i++){

		vector<int> b = a[i];
		for(int j=0;j<b.size();j++)
			cout<<b[j]<<",";
		cout<<"\n";
	}


}