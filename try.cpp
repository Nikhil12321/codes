#include<iostream>
#include<vector>
using namespace std;
int bitManip(vector<int> v){
    int i, j, ans, l;
    int lans;
    int n = v.size();
    ans = v[0];
    
    for(i=1; i<n; i++)
        ans = ans^v[i];

    for(l=2; l<=v.size(); l++){

        i=0;
        while(i<n){
            if(i+l-1 >= n){
           
                break;
            }
            lans = v[i];

            for(j=i+1; j<i+l && j<n; j++){

                lans = lans^v[j];
            }

            i++;
            ans = ans^lans;
        }
    }
    return ans;
}
int main(){
    int t, i, a, n;
    std::vector<int> v;
    int ans;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0; i<n; i++){
            cin>>a;
            v.push_back(a);
        }
        v.clear();
        ans = bitManip(v);
        cout<<ans<<endl;
        }
    }