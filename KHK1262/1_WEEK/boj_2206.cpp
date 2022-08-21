#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

using P = pair<pair<int, int>, int>;

int arr[1001][1001];
int visited[1001][1001][2];

int n, m;

int bfs(int x, int y) {
	queue<P> q;

	q.push({ {y,x}, 1 });
	visited[y][x][1] = 1;

	while (!q.empty()) {
		y = q.front().first.first;
		x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (y == n - 1 && x == m - 1) {
			if (visited[y][x][0] != 0 && visited[y][x][1] != 0)
				return min(visited[y][x][0], visited[y][x][1]);
			if (visited[y][x][0] == 0 && visited[y][x][1] != 0)
				return visited[y][x][1];
			else
				return visited[y][x][0];
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if ((0 <= nx && nx < m) && (0 <= ny && ny < n)) {
				if (arr[ny][nx] == 0 && cnt) {
					if (visited[ny][nx][1] != 0) {
						if (visited[ny][nx][1] > visited[y][x][1] + 1) {
							visited[ny][nx][1] = visited[y][x][1] + 1;
							q.push({ {ny, nx}, cnt });
						}
					}
					else {
						visited[ny][nx][1] = visited[y][x][1] + 1;
						q.push({ {ny, nx}, cnt });
					}
				}
				else if (arr[ny][nx] == 0 && !cnt) {
					if (visited[ny][nx][0] != 0) {
						if (visited[ny][nx][0] > visited[y][x][0] + 1) {
							q.push({ {ny, nx}, cnt });
							visited[ny][nx][0] = visited[y][x][0] + 1;
						}
					}
					else {
						q.push({ {ny, nx}, cnt });
						visited[ny][nx][0] = visited[y][x][0] + 1;
					}
				}
				else if (arr[ny][nx] == 1 && cnt) {
					if (visited[ny][nx][0] != 0) {
						if (visited[ny][nx][0] > visited[y][x][1] + 1) {
							q.push({ {ny, nx}, cnt - 1 });
							visited[ny][nx][0] = visited[y][x][1] + 1;
						}
					}
					else {
						q.push({ {ny, nx}, cnt - 1 });
						visited[ny][nx][0] = visited[y][x][1] + 1;
					}
				}
				else
					continue;
			}
		}
	}
	return -1;
}


int main() {

	cin >> n >> m;
	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}

	cout << bfs(0, 0) << endl;
}