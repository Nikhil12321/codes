#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
	

	int size, i, flag = 0;
	int k;
	cin>>size;
	cin>>k;
	unordered_map<int, int> m;
	int a[size];

	for(i = 0; i<size; i++){
		
		
		cin>>a[i];
		}
	

	for(i=0;i<size;i++){
	
		
		if(m.find(a[i]) != m.end()){
			
		
			if(i - m.at(a[i]) <= k){
				
				cout<<"flagged at "<<i<<endl;
				flag = 1;
				break;
			}
			else{
				m.at(a[i]) = i;
			}
		}
		else{
			
			pair<int, int> p(a[i], i);
			m.insert(p);
		}
	}

	cout<<flag<<endl;

}
