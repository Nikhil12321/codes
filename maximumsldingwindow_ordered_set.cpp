//does not work when duplicates are present since this is a set


#include<iostream>
#include<set>
#include<queue>
#include<vector>

using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {



	vector<int> ans;
	set<int> s;
	int i=0;
	int removed = 0;

	
	vector<int>::iterator it = nums.begin();

	while(i<k && it!=nums.end()){


		s.insert(*it);
		it++;
		i++;
	}

	set<int>::reverse_iterator set_it = s.rbegin();

	ans.push_back(*set_it);

	while(it != nums.end()){

		s.erase(nums[removed]);
		s.insert(*it);
		set<int>::reverse_iterator set_it = s.rbegin();
		ans.push_back(*set_it);
		it++;
		removed++;


	}

	return ans;






}

int main(){

	std::vector<int> v;
	int n;
	cin>>n;
	int k;
	cin>>k;
	int a;

	for(int i=0; i<n; i++)
	{

		cin>>a;
		v.push_back(a);

	}

	vector<int> temp = maxSlidingWindow(v, k);

	for(int i=0;i<temp.size();i++)
		cout<<temp[i]<<" ";
	cout<<endl;
}
