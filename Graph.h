#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<queue>
#include<cstring>
#include<stack>
#include<unordered_set>
using namespace std;
//UNWEIGHTED
class Graph{

    int **g;
    int vertices;

public:

    Graph(){vertices = 0;}
    Graph(int v){

        vertices = v;
        g = new int*[vertices+1];
        
        for(int i=0; i<=vertices; i++){

            g[i] = new int[vertices+1];

            for(int j=0; j<=vertices; j++){
                g[i][j] = 0;
            }
        }
    }

    void resize(int size){
        if(vertices == 0){
            vertices = size;
            g = new int*[size+1];
            for(int i=0; i<=size; i++){

                g[i] = new int[size+1];
                for(int j=0; j<=size; j++){
                    g[i][j] = 0;
                }
            }
        }
        else{
            //save in temp
            int temp[vertices+1][vertices+1];
            for (int i = 0; i <= vertices; ++i)
            {      
                for (int j = 0; j <= vertices; ++j)     
                {
                    temp[i][j] = g[i][j];
                }
            }

            //delete old g
            for (int i = 0; i <= vertices; ++i){
                delete[] g[i];
            }
            delete[] g;

            int old = vertices;
            vertices = size;
            //all zeroes of new
            g = new int*[vertices+1];
            for(int i=0; i<=vertices; i++){

                g[i] = new int[vertices+1];
                for(int j=0; j<=vertices; j++){
                    g[i][j] = 0;
                }
            }
            //copy old values
            for (int i = 0; i <= old; ++i)
            {      
                for (int j = 0; j <= old; ++j)     
                {
                    g[i][j] = temp[i][j];
                }
            } 
        }
        return;
    }

    void addEdge(int src, int dest){

        int max = (src>dest)?src:dest;
        if(max > vertices){
            resize(max);
        }
        if(g[src][dest] == 1)
            return;
        g[src][dest] = 1;
        g[dest][src] = 1;
        return;
    }
    void removeEdge(int src, int dest){

        int max = src>dest?src:dest;
        if(max > vertices)
            return;
        g[src][dest] = 0;
        g[dest][src] = 0;
    }
    void bfs(){
        if(vertices==0)
            return;
        queue<int> q;
        q.push(1);
        int visited[vertices+1];
        memset(visited, 0, sizeof(visited));
        visited[1] = 1;
        while(1){
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                cout<<temp<<" ";
                for(int i=1; i<=vertices; i++){
                    if((g[temp][i] == 1) && (visited[i]==0)){
                        q.push(i);
                        //really important to put 1 here and not above
                        visited[i] = 1;
                    }
                }
            }
            for(int i=1; i<=vertices; i++){
                if(visited[i] == 0){
                    q.push(i);
                    visited[i]=1;
                    break;
                }
            }
            if(q.empty())
                break;
        }  
    }
    void bfs(int source){
        if(vertices==0)
            return;
        queue<int> q;
        q.push(source);
        int visited[vertices+1];
        memset(visited, 0, sizeof(visited));
        visited[source] = 1;
        while(1){
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                cout<<temp<<" ";
                for(int i=1; i<=vertices; i++){
                    if((g[temp][i] == 1) && (visited[i]==0)){
                        q.push(i);
                        //really important to put 1 here and not above
                        visited[i] = 1;
                    }
                }
            }
            for(int i=1; i<=vertices; i++){
                if(visited[i] == 0){
                    q.push(i);
                    visited[i]=1;
                    break;
                }
            }
            if(q.empty())
                break;
        }  
    }
    void dfs(){
        if(vertices==0)
            return;
        stack<int> s;
        s.push(1);
        int visited[vertices+1];
        memset(visited, 0, sizeof(visited));
        visited[1] = 1;
        while(1){
            while(!s.empty()){
                int temp = s.top();
                s.pop();
                cout<<temp<<" ";
                for(int i=1; i<=vertices; i++){
                    if((g[temp][i] == 1) && (visited[i]==0)){
                        s.push(i);
                        //really important to put 1 here and not above
                        visited[i] = 1;
                    }
                }
            }
            for(int i=1; i<=vertices; i++){
                if(visited[i] == 0){
                    s.push(i);
                    visited[i]=1;
                    break;
                }
            }
            if(s.empty())
                break;
        }  
    }
    void dfs(int source){
        if(vertices==0)
            return;
        stack<int> s;
        s.push(source);
        int visited[vertices+1];
        memset(visited, 0, sizeof(visited));
        visited[source] = 1;
        while(1){
            while(!s.empty()){
                int temp = s.top();
                s.pop();
                cout<<temp<<" ";
                for(int i=1; i<=vertices; i++){
                    if((g[temp][i] == 1) && (visited[i]==0)){
                        s.push(i);
                        //really important to put 1 here and not above
                        visited[i] = 1;
                    }
                }
            }
            for(int i=1; i<=vertices; i++){
                if(visited[i] == 0){
                    s.push(i);
                    visited[i]=1;
                    break;
                }
            }
            if(s.empty())
                break;
        }  
    }
    void printShortestPath(int source, int dest){
        //!!!!!!!!!!!!!!!!!USE PARENT IN CASE OF BFS!!!!!!!!!!!!!!!!!!!!!!!
        int temp, flag=0;
        queue<int> q;
        if(vertices==0)
            return;
        q.push(source);
        std::vector<int> v;
        int visited[vertices+1];
        int parent[vertices+1];
        memset(visited, 0, sizeof(visited));
        memset(parent, -1, sizeof(parent));
        visited[source] = 1;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            
            for(int i=1; i<=vertices; i++){
                if((g[temp][i] == 1) && (visited[i]==0)){
                    q.push(i);
                    //really important to put 1 here and not above
                    visited[i] = 1;
                    parent[i] = temp;
                    if(i==dest){
                        flag =1;
                        break;
                    }
                }
            }
        }
        int i=dest;
        if(flag==1){
            while(parent[i] != -1){
                cout<<i<<" ";
                i = parent[i];
            }
            cout<<i; 
        }
        else
            cout<<"No path"; 
    }
    int connectedComponents(){
        int connectedComponent=0;
        queue<int> q;
        if(vertices==0)
            return 0;
        q.push(1);
        connectedComponent++;
        int visited[vertices+1];
        memset(visited, 0, sizeof(visited));
        visited[1] = 1;
        while(1){
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                cout<<temp<<" ";
                for(int i=1; i<=vertices; i++){
                    if((g[temp][i] == 1) && (visited[i]==0)){
                        q.push(i);
                        //really important to put 1 here and not above
                        visited[i] = 1;
                    }
                }
            }
            for(int i=1; i<=vertices; i++){
                if(visited[i] == 0){
                    visited[i]=1;
                    q.push(i);
                    connectedComponent++;
                    break;
                }
            }
            if(q.empty())
                break;
        }
        return connectedComponent;
    }
    bool edge(int src, int dest){
        if(g[src][dest]==1)
            return true;
        return false;
    }
    void printAdjMatrix(){
        for (int i = 1; i <=vertices; ++i)
        {
            for (int j = 1; j <=vertices; ++j)
            {
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    //pass by reference since we have to delete the second set
    void combine(unordered_set<int> &s1, unordered_set<int> &s2){
        unordered_set<int>::iterator it1 = s2.begin();
        while(it1!=s2.end()){
            s1.insert(*it1);
            it1++;
        }   
    }
    void minimumSpanningTree(){
        vector<unordered_set<int> > v;
        int mst[vertices+1][vertices+1];
        for (int i = 0; i <= vertices; ++i)
        {
            for(int j=0; j<=vertices; j++)
                mst[i][j] = 0;
        }
        //separate sets for each vertex
        for (int i = 1; i <=vertices; ++i)
        {
            unordered_set<int> temp;
            temp.insert(i);
            v.push_back(temp);
            temp.clear();
        }
        //since we want to erase the second set after combining, we need iterator to erase
        //also we need iterators to pass to the combine set function
        vector<unordered_set<int> >::iterator save1, save2;
        for(int i=1; i<=vertices; i++){
            //only the lower half of adjacency matrix is reqd. since we don't repeat edges
            for(int j=1; j<=i; j++){
                if(g[i][j] == 1){
                    //iterate through vector of sets
                    vector<unordered_set<int> >::iterator itv = v.begin();
                    while(itv!=v.end()){
                        //() are important since compiler confuses it with multiply operator
                        if((*itv).find(i) != (*itv).end()){
                            save1 = itv;
                        }
                        if((*itv).find(j) != (*itv).end()){
                            save2 = itv;
                        }
                        itv++;
                    }
                    if(save1!=save2){
                        //we pass value of iterators since value is the set int the vector
                        combine(*save1, *save2);
                        v.erase(save2);
                        mst[i][j]=1;
                        mst[j][i]=1;
                    }
                }
            }
        }
        //print the mst
        for(int i=0; i<=vertices; i++){
            for(int j=0; j<=vertices; j++){
                cout<<mst[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    bool isCyclePresent(){
        vector<unordered_set<int> > v;
        int mst[vertices+1][vertices+1];
        for (int i = 0; i <= vertices; ++i)
        {
            for(int j=0; j<=vertices; j++)
                mst[i][j] = 0;
        }
        //separate sets for each vertex
        for (int i = 1; i <=vertices; ++i)
        {
            unordered_set<int> temp;
            temp.insert(i);
            v.push_back(temp);
            temp.clear();
        }
        //since we want to erase the second set after combining, we need iterator to erase
        //also we need iterators to pass to the combine set function
        vector<unordered_set<int> >::iterator save1, save2;
        for(int i=1; i<=vertices; i++){
            //only the lower half of adjacency matrix is reqd. since we don't repeat edges
            for(int j=1; j<=i; j++){
                if(g[i][j] == 1){
                    //iterate through vector of sets
                    vector<unordered_set<int> >::iterator itv = v.begin();
                    while(itv!=v.end()){
                        //() are important since compiler confuses it with multiply operator
                        if((*itv).find(i) != (*itv).end()){
                            save1 = itv;
                        }
                        if((*itv).find(j) != (*itv).end()){
                            save2 = itv;
                        }
                        itv++;
                    }
                    //if cycle is found
                    if(save1==save2){
                        return true;
                    }
                    else if(save1!=save2){
                        //we pass value of iterators since value is the set int the vector
                        combine(*save1, *save2);
                        v.erase(save2);
                        mst[i][j]=1;
                        mst[j][i]=1;
                    }
                }
            }
        }
        return false;
    }
    bool isBipartite(){
        if(vertices==0)
            return true;
        queue<int> q;
        q.push(1);
        int visited[vertices+1];
        int group[vertices+1];
        memset(group, -1, sizeof(group));
        memset(visited, 0, sizeof(visited));
        visited[1] = 1;
        group[1] = 1;
        while(1){
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                for(int i=1; i<=vertices; i++){
                    if(g[temp][i] == 1){
                        if(group[i]==-1){
                            if(group[temp]==1)
                                group[i] = 2;
                            else
                                group[i] = 1;
                        }
                        else if((group[temp]-group[i]) == 0)
                            return false;

                        if(visited[i]==0){
                            q.push(i);
                            visited[i] = 1;
                        }
                    }
                }
            }
            for(int i=1; i<=vertices; i++){
                if(visited[i] == 0){
                    group[i]=1;
                    visited[i]=1;
                    q.push(i);
                    break;
                }
            }
            if(q.empty())
                break;
        }
        return true;
    }
};
#endif