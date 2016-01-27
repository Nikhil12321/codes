#include<iostream>
#include<vector>
using namespace std;

int abs(int a){
    if(a<0)
        a = -1*a;
    return a;
}

int threeSumClosest(vector<int>& v, int target){
    int i, start, end, n, number, abs_diff;
    int min_diff = 11111;
    int saved_number;
    sort(v.begin(), v.end());
    n = v.size();
    for(i=0; i<n-2;){
        start = i+1;
        end = n-1;
        while(start<end){
            //while((start<n-1) && (v[start]==v[start+1])){start++;}
            //while((end>start+1) && (v[end]==v[end-1])){end--;}
            number = v[i] + v[start] + v[end];
            abs_diff = abs(number - target);
            if(abs_diff < min_diff){
                min_diff = abs_diff;
                saved_number = number;
            }
            if(number - target < 0)
                start++;
            else
                end--;
        }
        
        //while((i<n-2)&&(v[i]==v[i+1]))
        //    i++;
        i++;
    }
    return saved_number;
}
int main(){

    int n, a;
    std::vector<int> v;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    
    int ans = threeSumClosest(v,1);
    cout<<ans<<endl;
    
    //cout<<binSearch(0, n-1, v, 2);
}