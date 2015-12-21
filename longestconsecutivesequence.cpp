#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;




pair<int, int> countConsecutive(vector<int> &v){



    int i, temp, min = 0, max = 0, globalmin, globalmax, count = 0;
    int number, maxcount = 0;
    unordered_set<int> m;

    if(v.size()==0)
        return 0;
    if(v.size()==1)
        return 1;


    for(i = 0; i<v.size(); i++)
        m.insert(v[i]);

    vector<int>::iterator it = v.begin();

    while(it != v.end()){


        count = 0;
        number = *it;
        temp = number;
        max = number;
        min = number;

        while(true){


            if(m.find(--temp) != m.end()){

                min = temp;
                count++;
                
                m.erase(m.find(temp));

            }
            else
                break;

        }

        temp = number;

        while(true){


            if(m.find(++temp) != m.end()){

                
                max = temp;
                count++;
                m.erase(m.find(temp));

            }
            else
                break;
        }

        if(count > maxcount){

            
            globalmax = max;
            globalmin = min;
            maxcount = count;

            
        }

        m.erase(number);

        ++it;
    }

    pair<int, int> p(globalmin, globalmax);
    return p;


}

int main(){



    vector<int> v;

    int size;
    int a;

    cin>>size;

    for(int i=0; i<size; i++){


        cin>>a;
        v.push_back(a);
    }


    pair<int, int> p = countConsecutive(v);

    for(int i =p.first; i<=p.second; i++)
        cout<<i<<" ";
    cout<<endl;
}



//https://leetcode.com/problems/longest-consecutive-sequence/