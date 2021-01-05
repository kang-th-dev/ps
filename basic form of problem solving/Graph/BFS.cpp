#include <iostream>
#include <cstdio>
#include "queue.h"
#include "graph.h"
using namespace std;

void bfs(graph g, int ee,int v){
    queue q(v);
    cout << ee <<" ";
    g.visited(ee, true);
    q.push(ee);
    while(!q.empty()){
        ee = q.pop();
        for(int i=1; i <=v; i++){
            if(g.isConnected(ee,i) && !g.visited(i)){
                g.visited(i, true);
                q.push(i);
                cout << i <<" ";
            }
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
    bfs(g,s,v);
} 