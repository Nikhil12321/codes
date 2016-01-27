#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;
    vector<vector<int> > threeSum(vector<int>& v) {
    sort(v.begin(), v.end());
    vector<vector<int> > s;
    int n=v.size();
    int i, j, find, start, end;
    //v[i]<=0 because first number has to negative in a sorted vector for the further 2 
    //numbers to sum to zero
    for(i=0; i<n-2 && v[i]<=0;){
        find = -1*v[i];
        start = i+1;
        end = n-1;
        while(start<end){
            int number = v[start]+v[end]+v[i];
            if(number==0){
                std::vector<int> a;
                a.push_back(v[i]);
                a.push_back(v[start]);
                a.push_back(v[end]);
                s.push_back(a);
                //keep moving till you find a different number
                while((start<n-1) && (v[start]==v[start+1])){start++;}
                //move to the different number
                start++;
                while((end>0) && (v[end]==v[end-1])){end--;}
                end--;
            }
            else if(number<0)
                start++;
            else
                end--;
        }
        //to move to the differnt number
        while(i<n-2 && v[i]==v[i+1]){i++;}
        i++;
    }
    return s;
}
int main(){

    int n, a;
    std::vector<int> v;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    
    vector<vector<int> > ans = threeSum(v);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j<ans[i].size(); ++j)
        {
            cout<<ans[i].at(j)<<" ";
        }
        cout<<endl;
    }
    
    //cout<<binSearch(0, n-1, v, 2);
}