#include<iostream>
#include<vector>
using namespace std;
/*
    Start looking from the back and subtract the largest 
    from the back with the current element.
    if the difference is +ve, add to sum
*/
long stockMax(vector<int> &v){
    int i, j, max;
    long sum;
    int n = v.size();
    int maxes[n];
    sum = 0;
    maxes[n-1] = 0;
    max = v[n-1];
    for(i=n-2; i>=0; i--){
        if(max-v[i] > 0)
            sum+=max-v[i];
        if(v[i] > max)
            max = v[i];
    }
    return sum;
}
int main(){
    int n, a;
    long ans;
    std::vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a;
        v.push_back(a);
    }
    ans = stockMax(v);
    cout<<ans<<endl;
}
//https://www.hackerrank.com/challenges/stockmax