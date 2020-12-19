#include <iostream>
#include <queue>
using namespace std;

int map[51][51] = { 0, };
bool visit[51][51] = { false, };
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int m, n, k;
bool isCheck(int x,int y) {
	return (0 <= x && x < m) && (0 <= y && y < n);
}
void dfs(pair<int,int> start) {
	visit[start.first][start.second] = true;
	for (int i = 0; i < 4; i++) {
		int x = start.first + dir[i][0];
		int y = start.second + dir[i][1];
		if (isCheck(x, y) &&map[x][y] == 1 && !visit[x][y] ) {
			dfs({ x,y });
		}
	}
}

int main() {
	int t;
	int x, y;
	cin >> t;

	while (t--) {
		
		cin >> m >> n >> k;
		//init map
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[x][y] = 1;
		}
		//connection elemnets check
		int con_cnt = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j] && map[i][j] == 1) {
					dfs({ i,j });
					con_cnt++;
				}
			}
		}
		
		cout << con_cnt<<"\n";
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				visit[i][j] = false;
				map[i][j] = 0;
			}
		}

	}
}