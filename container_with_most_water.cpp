#include<iostream>
#include<vector>

using namespace std;

int min(int a, int b){
    if(a<b)
        return 1;
    return 2;
}
int maxArea(vector<int>& height) {
    int temp, max = -111;
    int left = 0;
    int right = height.size()-1;
    while(left<right){
        int x = min(height[left], height[right]);
        if(x==1){
            temp = height[left]*(right-left);
            left++;
        }
        else{
            temp = height[right]*(right-left);
            right--;
        }
        if(temp>max)
            max = temp;
    }
    return max;
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
    int ans = maxArea(v);
    cout<<ans<<endl;
}