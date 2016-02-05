#include<iostream>
#include<vector>
using namespace std;
int aliceAndCandies(vector<int> a){
    int i, sum, j;
    int n = a.size();
    int ans[n];
    ans[0] = 1;
    
    for(i=1; i<n; i++){
        if(a[i-1] < a[i]){
            ans[i] = ans[i-1] + 1;
        }
        else{
            ans[i] = 1;
            if(ans[i-1] == 1){
                j = i;
                /*
                    I have no idea why we have to include a[j]<a[j-1] if we
                    already have ans[j]==a[j-1]. But the answer comes out wrong
                    if we don't. So..
                */
                while(ans[j] == ans[j-1] && j>=0 && (a[j] < a[j-1])){
                    ans[--j]++;
                }
            }
        }
    }
    sum = 0;
    for(i=0; i<n; i++){
        cout<<ans[i]<<" ";
        sum+=ans[i];
    }
    return sum;
}
int main(){
    std::vector<int> v;
    int a, n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    int ans = aliceAndCandies(v);
    cout<<ans<<endl;
}
//https://www.hackerrank.com/challenges/candies