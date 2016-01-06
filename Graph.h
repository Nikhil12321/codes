#ifndef Graph
#define Graph
#include<iostream>
using namespace std;
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

};
#endif