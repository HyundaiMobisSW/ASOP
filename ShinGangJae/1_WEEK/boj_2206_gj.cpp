#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m;
bool map[1001][1001];
bool visit[1001][1001][2];

typedef struct Point{
	int x, y, cnt;
}Point;

int solve() {
	queue<Point> q;
	int ans = 0;
	q.push({1, 1, 0});
	visit[1][1][0] = true;
	while (!q.empty()) {
		int size = q.size();
		ans++;
		while (size--) {
			int x = q.front().x;
			int y = q.front().y;
			int cnt = q.front().cnt;
			q.pop();
			if ((x == m) && (y == n)) return ans;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx <= 0 || ny <= 0 || nx > m || ny > n) continue;
				if (map[ny][nx]) {
					if (cnt || visit[ny][nx][1]) continue;
					else {
						q.push({ nx, ny, 1 });
						visit[ny][nx][1] = true;
					}
				}
				else {
					if (visit[ny][nx][cnt]) continue;
					q.push({ nx, ny, cnt });
					visit[ny][nx][cnt] = true;
				}
			}
		}
	}
	return -1;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int ans = solve();
	cout << ans;
}