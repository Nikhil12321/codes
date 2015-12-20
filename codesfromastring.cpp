#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printlist(string s, string done){


    if(s.size() <= 0){

        cout<<done<<endl;
        return;
    }

    string temp;
    string tempdone;
    int number;

    for(int i=1;(i<=2 && i<=s.size()); i++){


        tempdone = done;
        temp = s.substr(0, i);
        number = stoi(temp);

        if(number <= 0 || number > 26){


            continue;
        }


        if(i > 1 && s[0] == '0'){

                
                continue;
            }


        tempdone+=char(number+96);
        printlist(s.substr(i), tempdone);
        tempdone.clear();
        temp.clear();


    }
}



int main(){


    string s;

    cin>>s;
    string empty;

    printlist(s, empty);
}
