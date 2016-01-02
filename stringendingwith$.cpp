#include<iostream>
#include<string.h>
#include<unordered_map>


using namespace std;

int main(){


    string s;
    getline(std::cin, s);
    unordered_map<string, int> m;
    char *str;
    const char *brk = " $";
    int i;

    str = new char[s.size()];

    for(i = 0;i<s.size();i++)
        str[i] = s[i];

    

    char *p;

    p = strtok(str,brk);
    while(p!=0){

        //cout<<"p is "<<p<<endl;
        string ss(p);
        //cout<<"ss is "<<ss<<endl;
        if(m.find(ss) != m.end()){

            m.at(ss)++;
        }
        else
        {

            pair<string, int> pr(ss, 1);
            m.insert(pr);
        }
        cout<<"p is "<<p<<endl;
        p = strtok(0, brk);
    }



    unordered_map<string, int>::iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first<< " "<<it->second<<endl;
        it++;
    }

    return 0;
    
}