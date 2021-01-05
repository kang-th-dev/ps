#include <iostream>
#include <cstdio>
#include "graph.h"
using namespace std;

void dfs(graph g,int ee,int v){
    cout << ee <<" ";
    g.visited(ee, true);
    for(int i=1; i<=v; i++){
        if(g.isConnected(ee,i) && !g.visited(i)){
            dfs(g,i, v);
        }
    }
}

int main(){
    
        
    int v,e;
    //vertax&edge input

    int s; 
    cin >> v>>e >>s;
    graph g(v,e);
    
    //Expressing that two vertices are connected
    int v1,v2;
   
    //connect graph edge
    for(int i=0; i<e; i++){
        //Since it is a non-directional graph, it is symmetric.
        cin >>v1 >>v2;
        g.push(v1,v2);
        g.push(v2,v1);
    }
    dfs(g,s,v);
} 