#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
bool p[100001];

int BFS(int n,int k){
    queue<pair<int,int>> q;
    p[n]  = true;
    q.push({n,0});
    while(!q.empty()){
        int value = q.front().first;
        int time = q.front().second;
        q.pop();
        if(value == k){
            return time;
        }
        //walk
        int c  = value + 1;
        if(c<=100000 && !p[c]){
            p[c] = true;
            q.push({c, time +1});
        }
        c = value - 1;
        if(0<=c && !p[c]){
            p[c] = true;
            q.push({c, time +1});
        }
        c = 2 * value ;
        if(c<=100000 && !p[c]){
            p[c] = true;
            q.push({c, time +1});
        }
        //teleport
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    cout << BFS(n,k);
}