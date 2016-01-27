#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int findRegion(int posx, int posy, int n, int m, int **a);
int largestRegion(int n, int m, int **a){
    int i, j, size, max_size = -1111;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(a[i][j] == 1){
                size = findRegion(i, j, n, m, a);
                if(size > max_size)
                    max_size = size;
            }
        }
    }
    return max_size;
}
bool isOK(int posx, int posy, int n, int m, int **a){
    if(posx>=0 && posy>=0 && posx<n && posy<m && (a[posx][posy]==1))
        return true;
    return false;
}
pair<int, int> make_pair(int a, int b){
    pair<int, int> x;
    x.first = a;
    x.second = b;
    return x;
}
int findRegion(int posx, int posy, int n, int m, int **a){
    queue<pair<int, int> > q;
    q.push(make_pair(posx, posy));
    a[posx][posy] = 2;
    int size = 0;
    pair<int, int> x;
    int k, newx, newy;
    int Y[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int X[] = {0, -1, -1, -1, 0, 1, 1, 1};
    while(!q.empty()){
        x = q.front();
        q.pop();
        size++;
        //cout<<"pos is "<<x.first<<" "<<x.second<<endl;
        k = 0;
        while(k<8){
            if(isOK(x.first + X[k], x.second + Y[k], n, m, a)){
                q.push(make_pair(x.first+X[k], x.second+Y[k]));
                a[x.first+X[k]][x.second+Y[k]] = 2;
            }
            k++;
        }
    }
    return size;
}
int main(){
    int m, n, i, j;
    cin>>n>>m;
    int **a;
    a = new int*[n];
    for (i = 0; i < n; ++i)
    {   
        a[i] = new int[m];
        for (j = 0; j < m; ++j)
        {
            cin>>a[i][j];
        }
    }
    int ans = largestRegion(n, m, a);
    cout<<ans<<endl;
}

//https://www.hackerrank.com/challenges/connected-cell-in-a-grid