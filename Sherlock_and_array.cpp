#include<iostream>
#include<vector>

using namespace std;

void func(vector<int> &v, int sum){

    int i, suml, sumr, n;
    n = v.size();
    if(n==1)
    {
        cout<<"YES"<<endl;
        return;
    }

    sumr = sum-v[0];
    suml = 0;

    for (i = 0; i < n-1; ++i)
    {
        suml+=v[i];
        sumr-=v[i+1];
        if(suml==sumr){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}

int main(){

    int n, t, i, a;
    cin>>t;
    while(t--){
    int sum=0;
    std::vector<int> v;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        sum+=a;
        v.push_back(a);
    }
    func(v, sum);
    }
}