#include<iostream>
#include<string>
using namespace std;
void printMatrix(int mat[][100], int n){
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int palindromePartitioning(string &str){
    int i, j, n, start, end;
    n = str.size();
    int mat[n][n];
    /*
        in mat[i][j], if a string from i to j is a palindrome, then mat[i][j]=1 else 0
        */
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==j){
                mat[i][j] = 1;
                continue;
            }
            mat[i][j] = 0;
        }
    }
    for(i=1; i<n-1; i++){
        /*
        for odd length palindromes
        */
        start = i-1;
        end = i+1;
        while(str[start]==str[end] && start>=0 && end<n){
            mat[start][end] = 1;
            mat[end][start] = 1;
            start--;
            end++;
        }
        /*
        for even length palindromes
        */
        start = i-1;
        end = i;
        while(str[start]==str[end] && start>=0 && end<n){
            mat[start][end] = 1;
            mat[end][start] = 1;
            start--;
            end++;
        }
    }
    int dp[n];
    dp[0] = 0;
    for(i=1; i<n; i++){
        if(mat[i][0] == 1){
            dp[i] = 0;
            continue;
        }
        /*
            by the next line, we put  | before the concerned element, i'th element like
            if the concerned element is d in abcd, then we put a abc|d. And then check whether
            we can form less partitioning while moving backwards
            */
        dp[i] = dp[i-1]+1;
        /*
            We change dp[i] as soon as we find one with value less than the present.
            */
        for(j=i-1; j>0; j--){
            if(mat[i][j] == 1){
                if(dp[j-1] + 1 < dp[i]){
                    /*
                        if putting a | at j lessens the partitions, we put it and update its value
                        */
                    dp[i] = dp[j-1]+1;
                }
            }
        }
    }
    return dp[n-1];
}
int main(){
    string s;
    cin>>s;
    int ans = palindromePartitioning(s);
    cout<<ans<<endl;
}
//http://www.geeksforgeeks.org/dynamic-programming-set-17-palindrome-partitioning/