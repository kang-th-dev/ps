#include <iostream>
using namespace std;
//graph implement
class graph
{
private:
    int v,e;
    bool ** connected;
    bool * visit;
public:
    void push(int v1,int v2){connected[v1][v2] = true; }
    void visited(int ee, bool isVisit){visit[ee] = isVisit;}
    bool visited(int ee) { return visit[ee]; }
    bool isConnected(int v1,int v2){ return connected[v1][v2];}
    void print(){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                printf("%d ",connected[i][j]);
            }
            cout << endl;
        }
    }
    
    graph(int cv,int ce);
    ~graph();
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