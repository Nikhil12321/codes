#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> func(vector<int> nums, int target){

    vector<int> ans;
        unordered_map<int, int> map;
        
        for(int i=0; i<nums.size(); i++){
            pair<int, int> p(nums[i], i+1);
            map.insert(p);
        }
        unordered_map<int, int>::iterator it;
        
        for(int i=0; i<nums.size(); i++){
            
            ans.push_back(i+1);
            int number = target - nums[i];
            it = map.find(number);
            if(it!=map.end() && it->first != nums[i]){
                ans.push_back(it->second);
                return ans;
            }
            ans.clear();
        }


}

int main(){

    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    int target = 6;

    std::vector<int> ans = func(nums, target);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    
    
}

//https://leetcode.com/problems/two-sum/