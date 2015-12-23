#include<iostream>
#include<vector>
#include<stack>

using namespace std;



vector<int> span(vector<int> v){



    std::vector<int> ans;


    ans.push_back(1);


    int i = 1;


    while(i<v.size()){

        int num = 1;

        if(v[i-1]< v[i]){

            
            num+= ans[i-1];
            int steps = ans[i-1];
            int j = i-1-steps;

            while((v[j] < v[i]) && (j>0)){


                num+=ans[i-1-steps];
                j = j-ans[j];
            }

            
            
        }
        ans.push_back(num);
        i++;
    }

    return ans;
}


int main(){



    int n, i, a;
    std::vector<int> v, ans;


    cin>>n;

    for (int i = 0; i < n; ++i)
    {   
        
        cin>>a;
        v.push_back(a);
        }

    ans = span(v);

    for (int i = 0; i < ans.size(); ++i)
    {
        cout<<ans[i]<<" ";
    }

    cout<<endl;
}