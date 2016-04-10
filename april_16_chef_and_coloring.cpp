#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    int t, j, i, max;
    long long int n;
    cin>>t;
    string s;

    while(t--){
        cin>>n;
        cin>>s;
        unordered_map<char, int> m;
        m.insert(std::make_pair('R', 0));
        m.insert(std::make_pair('G', 0));
        m.insert(std::make_pair('B', 0));
        max = 0;
        for(j=0; j<s.size(); j++){
                m[s.at(j)]++;
                if(m[s.at(j)] > max){
                    max = m[s.at(j)];
                }
            }
        cout<<n-max<<"\n";    
    }
}