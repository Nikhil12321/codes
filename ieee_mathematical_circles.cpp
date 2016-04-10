#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>

using namespace std;

int abs(int a){
    if(a<0)
        return -1*a;
    return a;
}

int sq(int a){
    return a*a;
}

bool does_intersect(int i, int j, int x[], int y[], int r[]){
    int left = abs(sq(r[i] - r[j]));
    int right = sq(r[i] + r[j]);
    int middle = sq(x[i] - x[j]) + sq(y[i] - y[j]);

    if(left <= middle && middle <= right)
        return true;
    return false;
}

bool compare(const unordered_set<int> &a, const unordered_set<int> &b){
    return a.size()<b.size();
}

int main(){

    int n, i, j, count;
    bool intersect;

    cin>>n;
    int x[n], y[n], r[n];
    vector<unordered_set<int> > v;
    v.resize(n);

    for(i=0; i<n; i++){
        cin>>x[i]>>y[i]>>r[i];
    }

    /*
    * Intersect intersecting circles into the vector of sets
    */
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==j)
                continue;
            if(does_intersect(i, j, x, y, r)){
                v[i].insert(j);
                v[j].insert(i);
            }
        }
    }

    /*
    * In each iteration, select the circle with largest intersections
    * Remove the circle from the set of circle which it touches and also vice versa (duh)
    * Then check if any intersections remain.
    * !!!!!!!!!!!!!!! I FORGOT TO CHECK THE CONCENTRIC ONE SO DO IT TOO !!!!!!!!!!!!!!!!!!!!!!
    */
    count = 0;
    int max, pos;
    while(true == true){

        max = 0;
        for(i=0; i<v.size(); i++){
            if(max < v[i].size()){
                pos = i;
                max = v[i].size();
            }
        }
        intersect = false;

        for(j=0; j<n; j++){

            if(v[j].find(pos) != v[j].end()){

                intersect = true;
                v[j].erase(pos);
                v[pos].erase(j);
            }
        }
        if(intersect == false){
            cout<<count;
            return 0;
        }
        else{
            count++;
           
        }
    }
    
}