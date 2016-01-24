#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int ropeMinimumCost(std::vector<int> v){
    priority_queue<int, std::vector<int>, greater<int> > q;
    int n = v.size();
    int x, y, sum=0;
    int maxsum = 0;
    for (int i = 0; i < n; ++i)
    {
        q.push(v[i]);
    }
    while(q.size() > 1){
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        sum = x+y;
        maxsum+=sum;
        q.push(sum);
    }
    return maxsum;
}
int main(){

    int n,a;
    std::vector<int> v;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    int ans = ropeMinimumCost(v);
    cout<<ans<<endl;
}