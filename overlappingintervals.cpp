#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


void merge(vector<pair<int, int> > &v){


    sort(v.begin(), v.end());


    for(int i=0;i<v.size();i++){


        vector<pair<int, int> >::iterator it = v.begin();
        vector<pair<int, int> >::iterator it1 = v.begin();
        
        int f = it->first;
        int s = it->second;
        int temp;
        int count = 0;
        it++;


        while(count<v.size()){


            if(it->first < s){

                if(it1->second < it->second)
                    it1->second = it->second;


                v.erase(it);
            }

            else{

                it1 = it;
            }

            it++;
            count++;
        }

           
    }
}


int main(){




    vector<pair<int, int> > v;

    int size, a, b;

    

    cin>>size;

    for(int i =0;i<size; i++){

        cin>>a>>b;
        pair<int, int> p(a, b);
        v.push_back(p);
    }

    merge(v);

    for(int i=0;i<v.size();i++)
        cout<<v[i].first<< " "<<v[i].second<<endl;
}



//https://leetcode.com/problems/merge-intervals/