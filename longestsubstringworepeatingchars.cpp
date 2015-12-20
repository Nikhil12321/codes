#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


int main(){



    string str;

    cin>>str;


    unordered_map<char, int> m;
    int posleft = 0;
    int i = 0;
    int maxl = -1111;
    int lmax = -1;
    int rmax = -1;

    while(str[i]){
        



        if(m.find(str[i]) == m.end()){


            
            pair<char, int> p(str[i], i);
            m.insert(p);
             
            if(i - posleft > maxl){

                lmax = posleft;
                rmax = i;
                maxl = i - posleft;
            }
        }

        else if( m.at(str[i]) < posleft){


            

                m.erase(str[i]);
                pair<char, int> y(str[i], i);
                m.insert(y);

                if(i - posleft > maxl){

                lmax = posleft;
                rmax = i;
                maxl = i - posleft;
                }
            
        }

        else{


            posleft = m.at(str[i])+1;

            m.erase(str[i]);
            pair<char, int> x(str[i], i);
            m.insert(x);
        }

        i++;
    }

    cout<<lmax<< " "<<rmax<<endl;

  


}

//https://leetcode.com/problems/longest-substring-without-repeating-characters/