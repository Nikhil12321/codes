#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b){
    return (a>b)?a:b;
}
int maxSum(std::vector<int> v){

    int sum = 0;
    int n = v.size();
    int ans[n+1];

    if(n==2)
        return max(v[0], v[1]);

    ans[n] = 0;
    ans[n-1] = v[n-1];
    ans[n-2] = v[n-2];

    for(int i = n-3; i>=0; i--){
        ans[i] = max(ans[i+2]+v[i], ans[i+3]+v[i]);

    }
    return max(ans[0], ans[1]);
}

int main(){

    std::vector<int> v;
    int n;
    int a;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    int ans = maxSum(v);
    cout<<ans<<endl;
}