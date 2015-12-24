#include<iostream>
#include<queue>
#include<utility>



using namespace std;


int main(){


    int m[][4] = {{1, -1, -1, -1},
                {-1, 1, -1, -1},
                {1, -1, 1, -1},
                {-1, 1, -1, 1}};

    int n=4;


    queue<pair<int, int> > q;

    int i, j, posx, posy, destx, desty, a, b;

    int count=0;

    posx = 0;
    posy = 0;
    destx = 3;
    desty = 3;


    pair<int, int> parent[4][4];
    pair<int, int> curr;


    for(i=0; i<n;i++){

        for(j=0; j<n; j++){

            parent[i][j].first = -1;
            parent[i][j].second = -1;
        }
    }

    q.push(make_pair<int, int>(posx, posy));

    int X[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int Y[] = {0, -1, -1, -1, 0, 1, 1, 1};


    while(!q.empty()){


        curr = q.front();
        q.pop();
        cout<<"went to "<<curr.first<<" "<<curr.second<<endl;
        if(curr == make_pair<int, int>(destx, desty))
            break;

        for (i = 0; i < 8; ++i)
        {   
            a = curr.first+X[i];
            b = curr.second+Y[i];
            if(a>=0 && b>=0 && a<n && b<n){
                if(m[a][b] != -1){

                    if(parent[a][b] == make_pair<int, int>(-1, -1)){

                        parent[a][b] = make_pair<int, int>(curr.first, curr.second);
                        q.push(make_pair<int, int>(a, b));
                    }
                }

            }
        }
    }


    if(curr == make_pair<int, int>(destx, desty)){


        
        while(curr!=make_pair<int, int>(posx, posy)){

            cout<<curr.first<<" "<<curr.second<<endl;
            curr = parent[curr.first][curr.second];
            count++;
        }
        cout<<posx<<" "<<posy<<endl;
    }

    cout<<"count is "<<count<<endl;



}

