#include <iostream>
#include <queue>
using namespace std;
int n,m;
int matrix[1001][1001] = {0,};
bool visited[1001] = {false,};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void DFS(int v){
    cout << v<<" ";
    visited[v] =true;
    for(int i=1; i <=n; i++){
        if(matrix[v][i] == 1 && visited[i] == false){
            DFS(i);
        }
    }
}
void BFS(int v){
    queue<int> q;
    q.push(v);
    visited[v] = true;
    cout << v << " ";
    while(!q.empty()){
         v = q.front();
         q.pop();
         for(int i=1; i <=n; i++){
             if(matrix[v][i] == 1 && visited[i] == false){
                 visited[i]= true;
                 q.push(i);
                 cout << i << " ";
             }
         }
    }
}

int main(){
    int v;
    cin >>n>>m>>v;
    int x,y;
    for(int i=0; i< m; i++){
        cin >>x>>y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
  
    }
    DFS(v);
    for(int i=1; i<=n; i++) visited[i] = false;

    cout << "\n";
    BFS(v);
}