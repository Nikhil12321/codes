#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>

using namespace std;



struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };


int main(){


    int i, j, max = INT_MIN;
    float slope;
    Point a[10];
    vector<Point> v;
    int size;
    unordered_map<float, int> m;

    cin>>size;

    for(i=0; i<size;i++){
        
        cin>>a[i].x;
        cin>>a[i].y;
        v.push_back(a[i]);

    }

    size = v.size();


    if(size==0)
            return 0;
            
    max = 1;
        


    for(i = 0; i<size; i++)
    {
        m.clear();

        for(j = i+1; j<size; j++){

            if(v[i].x - v[j].x == 0){

                if(v[i].y - v[j].y == 0){

                    slope = INT_MIN;
                    
                }

                slope = INT_MAX;
            }
            else
                slope = (float(v[i].y) - float(v[j].y))/(float(v[i].x) - float(v[j].x));

            if(m.find(slope) != m.end()){

                m.at(slope)++;

                if(m.at(slope) > max)
                    max = m.at(slope);
            }
            else{
                pair<double, int> p(slope, 2);
                m.insert(p);
                if(2 > max)
                    max = 2;
            }
        }
    }

    cout<<max<<endl;

}


//https://leetcode.com/problems/max-points-on-a-line/