#include<iostream>
#include<vector>
#include<unordered_set>
#include<math.h>
using namespace std;
 
vector<vector<long long int> > gen_subsets(vector<long long int> a, long long int pos){
 
    
 
    if(pos == a.size()){
 
        std::vector<long long int> v;
        vector<vector<long long int> > w;
        w.push_back(v);
        return w;
 
 
    }
 
    vector<vector<long long int> > temp = gen_subsets(a, pos+1);
    long long int ss = temp.size();
 
    for(long long int i =0;i<ss;i++){
 
        std::vector<long long int> v = temp[i];
        v.push_back(a[pos]);
        temp.push_back(v);
 
    }
 
    return temp;
 
}
 
 
void fibonacci(long long int *fib, long long int pos_fib, long long int find){
 
    int mod = 1000000007;
 
    if(pos_fib != 0){
 
        long long int *temp;
        temp = new long long int[find+1];
        for(int i=0; i<=pos_fib; i++){
            temp[i] = fib[i];
        }
        delete fib;
        fib = temp;
        for(int i=pos_fib+1; i<=find; i++){
            fib[i] = (fib[i-1] + fib[i-2])%mod;
        }
    }
    else{
 
        fib[0] = 0;
        fib[1] = 1;
        fib[2] = 1;
        for(long long int i=3; i<=find; i++){
            long long int x = (fib[i-1] + fib[i-2])%mod;
            fib[i] = x;
        }
    }
}
 
 
void printFib(long long int *fib, long long int size){
    for(int i=0; i<=size; i++)
        cout<<fib[i]<<" ";
    cout<<"\n";
}
 
 
int main(){
    
    long long int mod = 1000000007;
    long long int n, m, start, end, i, j, k, size, sum, pos_fib, temp_size, s, set_sum, total_sum, diff, input_var;
    char ch;
    long long int *fib;
 
    cin>>n>>m;
    long long int *arr;
    arr = new long long int[n];
    sum = 0;
 
    for(i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    fib = new long long int[sum+1];
 
    pos_fib = sum;
    fibonacci(fib, 0, sum);
    printFib(fib, sum);
    for(i=0; i<m; i++){
        cin>>ch>>start>>end;
        if(ch == 'Q'){
            temp_size = end - start + 1;
            long long int *a;
            a = new long long int[temp_size];
            s = start - 1;
            for(j=0; j<temp_size; j++){
                a[j] = arr[s+j];
            }
            total_sum = 0;
 
            long long int pow_set_size = pow(2, temp_size);
            long long int counter;
            for(counter = 0; counter<pow_set_size; counter++){
                
                set_sum = 0;
                
                for(j=0; j<temp_size; j++){
                    
                    if(counter & (1<<j)){
                        set_sum = (set_sum + a[j])%mod;
                    }
                }
                total_sum = (total_sum + fib[set_sum])%mod;
            }
 
            cout<<total_sum<<"\n";
            delete a;
        }
 
        if(ch == 'C'){
            if(end > arr[start - 1]){
                diff = end - arr[start - 1];
                fibonacci(fib, sum, sum+diff);
                sum = (sum + diff)%mod;
                printFib(fib, sum+diff);
            }
            arr[start-1] = end;
        }
    }
}