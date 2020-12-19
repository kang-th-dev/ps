#include <iostream>
#include <queue>
#include <algorithm>
#define INF 999999
using namespace std;

int map[1001][1001];
int visited[1001][1001] = {0,};
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int m, n;
queue<pair<int, int>> q;

bool isCheck(int x,int y) {
	return (0 <= x && x < n) && (0<=y && y<m);
}

void bfs() {
	while (!q.empty()) {
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int moveX = nowX + dir[i][0];
			int moveY = nowY + dir[i][1];
			if (isCheck(moveX, moveY) && map[moveX][moveY] == 0 && visited[moveX][moveY ] == 0) {
				visited[moveX][moveY]= visited[nowX][nowY] + 1;
				q.push({ moveX,moveY });
			}
		}
	}

}
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({i,j});
			}
		}
	}
	int cnt = 0;

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0 && visited[i][j] == 0) {
				cout << "-1" << endl;
				return 0;
			}
			cnt = max(cnt, visited[i][j]);
		}
	}
	cout << cnt << endl;
}