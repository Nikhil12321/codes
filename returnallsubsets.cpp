#include<iostream>
#include<vector>


using namespace std;



void power_set_algo(){
			int a[];
            long long int pow_set_size = pow(2, temp_size);
            long long int counter;
            for(counter = 0; counter<pow_set_size; counter++){
                
                set_sum = 0;
                
                for(j=0; j<temp_size; j++){
                    
                    if(counter & (1<<j)){
                        cout<<a[j]<<" ";
                    }
                }
                cout<<"\n";
            }
}









//Repetitive elements
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



//For distinct elements (non repetitve)
vector<unordered_set<int> > gen_subsets(int arr[], int pos, int n){
    vector<unordered_set<int> > s;
    if(pos >= n)
        return s;

    vector<unordered_set<int> > ans, temp;
    temp = gen_subsets(arr, pos+1, n);
    int i;

    //Copy all the old subsets
    for(i=0; i<temp.size(); i++){
        ans.push_back(temp[i]);
    }

    //Make the new with the current element inserted
    for(i=0; i<temp.size(); i++){
        unordered_set<int> tt = temp[i];
        tt.insert(arr[pos]);
        ans.push_back(tt);
    }
    unordered_set<int> x;
    x.insert(arr[pos]);
    ans.push_back(x);
    return ans;
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