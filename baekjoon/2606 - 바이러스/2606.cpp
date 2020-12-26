#include <iostream>
#include <queue>
using namespace std;
int n,m;
int matrix[101][101] = {0,};
bool visited[101] = {false,};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int BFS(int v){
    int cnt =0;
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while(!q.empty()){
         v = q.front();
         q.pop();
         for(int i=1; i <=n; i++){
             if(matrix[v][i] == 1 && visited[i] == false){
                 visited[i]= true;
                 cnt++;
                 q.push(i);
             }
         }
    }
    return cnt ;
}


int main(){
    cin >>n>>m;
    int x,y;
    for(int i=0; i< m; i++){
        cin >>x>>y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
  
    }
    cout << BFS(1);

}