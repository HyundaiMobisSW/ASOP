#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define MAX 50
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m;

int graph[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];


int dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || graph[x][y] == 0) return 0;
	if (visited[x][y]) return -1;

	if (dp[x][y]) return dp[x][y];

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + graph[x][y] * dx[i];
		int ny = y + graph[x][y] * dy[i];

		int result = dfs(nx, ny);
		if (result == -1) return -1;
		dp[x][y] = max(dp[x][y], result + 1);
	}

	visited[x][y] = false;
	return dp[x][y];
}


int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'H') graph[i][j] = 0;
			else graph[i][j] = s[j] - '0';
		}
	}


	cout << dfs(0, 0) << endl;

}