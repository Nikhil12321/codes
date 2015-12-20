#include<iostream>
#include<string>
#include<vector>

using namespace std;



void ipaddress(string s, int size, int pos, string ip, vector<string> &v){


    int number;

    if(pos == 3){

  
        if(s.size() > 3){

            return;
        }

        else{
          
            string temp;
            temp+='.';

            number = stoi(s);

            if(number>255)
                return;
            if(s.size() > 1 && s[0] == '0'){

                
                return;
            }
            temp+=s;
            ip+=temp;
            cout<<"ip  is "<<ip<<endl;
            v.push_back(ip);
            return;
        }
    }


    if(s.size() < 4-pos)
        return;
    string temp;
    string tempip;

    for(int i = 1;(i<=3 && i<s.size());i++){

        tempip = ip;
        temp+='.';
        cout<<"substring is "<<s.substr(0, i)<<" sent substr is "<<s.substr(i)<<" position is "<<pos<<endl;
        number = stoi(s.substr(0, i));
        if(number > 255)
            continue;
        if(i > 1 && s[0] == '0'){

                
                continue;
            }
        temp+=s.substr(0, i);
        
        tempip+=temp;
        ipaddress(s.substr(i), size, pos+1, tempip, v);
        temp.clear();
        tempip.clear();


    }



}

int main(){



    string s;
    vector<string> v;
    string empty;

    cin>>s;

    ipaddress(s, s.size(), 0, empty, v);


    for(int i=0;i<v.size();i++)
        v[i] = v[i].substr(1);

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;





}


//https://leetcode.com/problems/restore-ip-addresses/