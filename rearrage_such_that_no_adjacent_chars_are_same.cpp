#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

struct Element{
    
    char ch;
    int freq;
    
    Element(char c, int f){
        
        ch = c;
        freq = f;
    }
};

class Compare{
    
    public:
    
    bool operator()(Element e1, Element e2){
        if(e1.freq < e2.freq)
            return true;
        return false;
    }
};

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        
        string s;
        cin>>s;
        unordered_map<char, int> m;
        for(int i=0; i<s.size(); i++){
            
            if(m.find(s[i]) == m.end()){
                m.insert(pair<char, int>(s[i], 1));
            }
            else
                m.at(s[i])++;
        }
        vector<Element> v;
        for(auto it = m.begin(); it != m.end(); it++){
            
            char c = it->first;
            int f = it->second;
            Element x(c,f);
            v.push_back(x);
        }
        priority_queue<Element, vector<Element>, Compare> pq(v.begin(), v.end());

        Element prev('a', 0);
        string ans = "";
        while(!pq.empty()){

            Element present = pq.top();
            pq.pop();
            ans += present.ch;
            present.freq--;

            if(prev.freq > 0)
                pq.push(prev);
            prev = present;
        }
        if(ans.size() != s.size())
            cout<<0<<endl;
        else
            cout<<1<<endl;

    }
    
    return 0;
}