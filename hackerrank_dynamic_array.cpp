#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){

    int n, q, xorr, lastans, ans, i, op, x, y, seq, related_size;
    unordered_map<int, vector<int> > m;
    unordered_map<int, int> size;
    lastans = 0;
    cin>>n>>q;
    for(i=0; i<q; i++){
        cin>>op>>x>>y;
        if(op == 1){
            xorr = (x^lastans)%n;
            //m.at(xorr).push_back(y);
            if(m.find(xorr) == m.end()){
                vector<int> temp;
                temp.push_back(y);
                m.emplace(xorr, temp);

            }
            else
                m.at(xorr).push_back(y);

            if(size.find(xorr) == size.end()){
                size.emplace(xorr, 1);
            }
            else
                size.at(xorr)++;
        }
        else if(op == 2){
            seq = (x^lastans)%n;
            related_size = y%(size.at(seq));
            ans = m.at(seq)[related_size];
            cout<<ans<<"\n";
            lastans = ans;
        }
    }
}// https://www.hackerrank.com/challenges/dynamic-array