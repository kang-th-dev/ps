#include <iostream>
#include <cstdio>
#include "graph.h"
using namespace std;


int main(){
        
    int v,e;
    //vertax&edge input

    int s; 
    scanf("%d%d",&v,&e);
    graph g(v,e);
    
    //Expressing that two vertices are connected
    int v1,v2;
    for(int i=0; i<e; i++){
        cin >>v1 >>v2;
        g.push(v1,v2);
        g.push(v2,v1);
    }
    g.print();
}