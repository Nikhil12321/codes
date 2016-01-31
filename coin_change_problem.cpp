#include<iostream>
#include<vector>
using namespace std;
int coinChange(vector<int> &v, int n){
    
    int m = v.size();
    int i, j, num;
    int x;
    int ans[n+1][m];
    
    for(i=0; i<m; i++){
        ans[0][i] = 1;
        }
    
        for(j=0; j<m; j++){
    for(i=1; i<=n; i++){
        
            num = i-v[j];
            if(num<0)
                num = 0;
            else
                num = ans[num][j];
                
                if(j<1)
                    x = 0;
                else
                    x = ans[i][j-1];
            
            ans[i][j] = num + x;
            
            }
        }
        return ans[n][m-1];
    }
    int main(){
        int n, a;
        int target;
        cin>>target;
        cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++){
            cin>>a;
            v.push_back(a);
            }
        int ans = coinChange(v, target);
        cout<<ans<<endl;
    }