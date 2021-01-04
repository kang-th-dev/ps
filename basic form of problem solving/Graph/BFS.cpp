#include <iostream>
#include <cstdio>
using namespace std;
//queue implement
class queue{
    private:
        int v;
        int rear,front,size;
        int *q;
    public:
        queue(int v);
        ~queue();
        bool empty();
        void push(int v);
        int pop();
        
};
bool queue::empty(){
   return rear- front !=0 ? false : true; 
}
void queue::push(int v){
    q[rear ++] = v;
}
int queue::pop(){
    return q[front++];
}

//constructor
queue::queue(int v){
    this->v = v;
    q = new int[v];
    rear = 0;
    front = 0;
    size = 0;
}

//destroy
queue::~queue(){
    delete[] q;
}

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