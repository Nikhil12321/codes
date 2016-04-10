#include<iostream>
using namespace std;

/*
* Faster exponentiation function to use if answer is in modulo
* Also we can SOMEHOW use int even if the modulo is sooooooo freaakin' big
*/
long long int power(long long int a, long long int b){
    int M = 1000000007;
    int result = 1;
    while(b>0){
        if(b%2==1)
            result = (result * a)%M;
        b = b>>1;
        a = (a*a)%M;
    }
    return result;
}
/*
* Linear parent child hierarchy. Every parent has only one child
*/
int main(){
    
    long long int x = 1000000007;
    long long int t, n, k;
    long long int ans;
    cin>>t;
    while(t--){
        cin>>n>>k;
        /*
        * Do NOT write ans = ans%x in the next step. Do it in this step itself
        * See it in the modulo rules given in the quora answer link below
        */
        ans = (k%x * power(k-1, n-1))%x;
        cout<<ans<<"\n";
    }
}
// https://www.quora.com/What-exactly-is-print-it-modulo-10-9-+-7-in-competitive-programming-websites