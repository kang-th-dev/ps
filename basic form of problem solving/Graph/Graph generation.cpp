#include <iostream>
#include <cstdio>
using namespace std;

/*
    ### Common graph form ###
    Expressed mainly in non-direction.

    To express as a directed graph, change the variable 
     "visit" in the graph class to a double array.
*/
class graph
{
private:
    int v,e;
    //Are the two vertices connected?
    bool ** connected;
    bool * visit;
public:
    void push(int v1,int v2){connected[v1][v2] = true; }
    void visited(int ee, bool isVisit){visit[ee] = isVisit;}
    bool isVisited(int ee) { return visit[ee]; }
    bool isConnected(int v1,int v2){ return connected[v1][v2];}
    graph(int cv,int ce);
    ~graph();
     
    //test print
    void print(){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                printf("%d ",connected[i][j]);
            }
            cout << endl;
        }
    }
    
};

//constructor
graph::graph(int cv,int ce)
{
    this->v = cv;
    this->e = ce;
    connected = new bool* [cv+1];
    for(int i=1; i <=cv; i++){
        connected[i] = new bool [cv+1];
    }
    
    visit = new bool[cv+1];
    
    //initilaze
    for(int i=1; i <=cv; i++){        
        visit[i] = false;
        for(int j=1; j <=cv; j++){
            connected[i][j] = false;
        }
    }
}

//destroy
graph::~graph()
{
    delete[] connected;
    delete[] visit;
}
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