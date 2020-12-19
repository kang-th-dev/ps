#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int map[101][101];
int visit[101][101];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int n, m;
pair<int, int> start;
bool isCheck(int fx,int fy) {
	return (1 <= fx && fx <= n) && (1 <= fy && fy <= m);
}
int BFS() {
	queue<pair<int, int>> q;
	visit[start.first][start.second] = 1;
	q.push({ start.first ,start.second });
	while (!q.empty()) {
		int preX = q.front().first;
		int preY = q.front().second;
		q.pop();
		if (preX == n && preY == m) {
			return visit[preX][preY];
		}
		for (int i = 0; i < 4;i++) {
			int curX = preX + dir[i][0];
			int curY = preY + dir[i][1];
			if (isCheck(curX, curY) && visit[curX][curY] ==0 &&map[curX][curY]==1) {
				visit[curX][curY] = visit[preX][preY] + 1;
				q.push({ curX,curY });

			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);

	//조건
	start = { 1,1 };
	
	
	cout << BFS();

}