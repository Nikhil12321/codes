#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printArr(int **m, int n){
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}
vector<vector<string> > partition(string s) {
    int i, j, n, k, start, end;
    n = s.size();
    int **mat;
    mat = new int*[n];
    string str;
    for(i=0; i<n; i++){
        mat[i] = new int[n];
        for(j=0; j<n; j++)
            mat[i][j] = 0;
    }
    for(i=0; i<n; i++){
        mat[i][i] = 1;
        start = i-1;
        end = i+1;
        while(start>=0 && end<n && s[start]==s[end]){
            mat[start][end] = 1;
            start--;
            end++;
        }
        start = i-1;
        end = i;
        while(start>=0 && end<n && s[start]==s[end]){
            mat[start][end] = 1;
            start--;
            end++;
        }
    }
    printArr(mat, n);
    vector<vector<string> > dp[n];
    vector<string> v;
    v.push_back(s.substr(n-1, 1));
    dp[n-1].push_back(v);
    for(i=n-2; i>=0; i--){
        for(j=i; j<n-1; j++){
            if(mat[i][j]==1){
                for(int z=0; z<dp[j+1].size(); z++){
                    str = s.substr(i, j-i+1);
                    dp[i].push_back(dp[j+1][z]);
                    int si = dp[i].size()-1;
                    dp[i][si].insert(dp[i][si].begin(),str);
                    /*
                    str = s.substr(i, j-i+1);
                    for(k=0; k<dp[i][si].size(); k++){
                        dp[i][si][k] = str+dp[i][si][k];
                    }
                    */
                }
            }
        }
        if(mat[i][n-1]==1){
            vector<string> temp;
            string tempp = s.substr(i);
            temp.push_back(tempp);
            dp[i].push_back(temp);
        }
    }
    
    return dp[0];
}
int main(){
    string s;
    s = "aaba";
    vector<vector<string> > ans = partition(s);
    for (int i = 0; i < ans.size(); ++i)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    
}

//https://leetcode.com/problems/palindrome-partitioning/
