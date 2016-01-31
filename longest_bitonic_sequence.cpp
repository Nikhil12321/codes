#include<iostream>
#include<vector>
using namespace std;
int max(int a, int b){
    return (a>b)?a:b;
}
int longestBitonicSequence(vector<int> &a){
    int i, j, max_seq, sum;
    int n = a.size();
    int lis[n];
    int dis[n];
    lis[0] = 0;
    for(i=1; i<n; i++){
        lis[i] = 1;
        for(j=0; j<i; j++){
            if(a[i] > a[j] && lis[j]+1 > lis[i])
               lis[i] = lis[j] + 1;
        }
        //cout<<"lis of "<<a[i]<<" is "<<lis[i]<<endl;
    }
    dis[n-1] = 1;
    for(i=n-2; i>=0; i--){
        dis[i] = 0;
        for(j = n-1; j>i; j--){
            if(a[i] > a[j] && dis[i] < dis[j]+1)
                dis[i] = dis[j]+1;
        }
    //cout<<"dis of "<<i<<" is "<<dis[i]<<endl;
    }
    max_seq = max(lis[n-1], dis[0]);
    
    for(i=1; i<n-1; i++){
        sum = lis[i]+dis[i];
        max_seq = max(max_seq, sum);
    }
    
    return max_seq;
}
int main(){
    std::vector<int> v;
    int i, a, n;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>a;
        v.push_back(a);
    }
    int ans = longestBitonicSequence(v);
    cout<<ans<<endl;
}