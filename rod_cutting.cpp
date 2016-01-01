#include<iostream>
#include<vector>
#include<climits>

using namespace std;



int rodCutting(vector<int> &prices){



    int n = prices.size();
    int i, j;
    int ans[n+1];

    ans[0] = 0;

    for(j = 1; j<=n; j++){


        int max = INT_MIN;

        for(i = 0; i<j; i++){

            if(prices[j-i-1] + ans[i] > max)
                max = prices[j-i-1] + ans[i];
        }

        ans[j] = max;
    }

    return ans[n];

}

int main(){


    std::vector<int> v;

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {

        int a;
        cin>>a;
        v.push_back(a);
    }

    int ans = rodCutting(v);
    cout<<ans<<endl;
}