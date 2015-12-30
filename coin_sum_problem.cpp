#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b){

    if(a>b)
        return a;
    return b;
}

int coinProblem(vector<int> coins, int n){



    int i, j, temp, min, x;

    vector<int> ans(n+1, -1);

    //ans.reserve(coins.size());

    for(i=0; i<coins.size(); i++){
        ans[coins[i]] = 1;
    }

    for(i=1; i<=n; i++){

        if(ans[i] != -1)
            continue;

        min = 1111;

        for(j=0; j<coins.size(); j++){

            x = i-coins[j];
            if(x > 0){

                temp = 1+ans[x];
                if(temp < min)
                    min = temp;
            }
        }
        ans[i] = min;
    }

    return ans[n];
    

}


int main(){


    std::vector<int> v;

    int n, a;
    int mx = -11111;
    cin>>n;
    for(int i=0; i<n; i++)
    {

        cin>>a;
        v.push_back(a);
        if(a>mx)
            mx = a;

    }

    cout<<coinProblem(v, 14);
}