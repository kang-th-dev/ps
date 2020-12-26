#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int n;
int matrix[26][26] = {0,};
bool visited[26][26] = {false,};
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int city[626] = {0,};
int city_num =0;
int BFS(pair<int,int> v){
    int cnt =1;
    queue<pair<int,int>> q;
    q.push(v);
    visited[v.first][v.second] = true;
    while(!q.empty()){
         int x = q.front().first;
         int y = q.front().second;
         q.pop();
         for(int i=0;i<4; i++){
             int nx = x + dir[i][0];
             int ny = y + dir[i][1];
             if(!(0<= nx && nx < n)) continue;
             if(!(0<= ny && ny < n)) continue;
             if(matrix[nx][ny] == 1 && visited[nx][ny] == false){
                 visited[nx][ny]= true;
                 cnt++;
                 q.push({nx,ny});
             }
         }
    }
    return cnt ;
}


int main(){
    cin >>n;
    for(int i=0; i< n; i++){
        for(int j=0; j< n; j++){
            scanf("%1d",&matrix[i][j]);
        }
  
    }    
    for(int i=0; i< n; i++){
        for(int j=0; j< n; j++){
            if(matrix[i][j] == 1&&!visited[i][j]){
                city[city_num++] = BFS({i,j});
            }
        }
    }
    cout << city_num<<"\n";
    sort(city, city+city_num);
    for(int i=0; i< city_num; i++){
        cout << city[i] <<"\n";
    }

}
