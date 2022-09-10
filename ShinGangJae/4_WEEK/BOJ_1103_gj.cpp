#include <iostream>
#include <memory.h>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

#define max(a, b) (a > b ? a : b)

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m;
int ans;
string map[51];
int dp[51][51];
vector<pair<int, int>> route;

int getAnswer(int x, int y) {
	if (map[y][x] == 'H') return dp[y][x];
	if (dp[y][x] != -1) return dp[y][x];
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i] * (map[y][x] - '0');
		int ny = y + dy[i] * (map[y][x] - '0');
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;;
		route.push_back(make_pair(nx, ny));
		int cnt = count(route.begin(), route.end(), make_pair(nx, ny));
		if (cnt >= 2) {
			cout << -1;
			exit(0);
		}
		dp[y][x] = max(dp[y][x], getAnswer(nx, ny) + 1);
		route.pop_back();
	}
	return dp[y][x];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) memset(dp[i], -1, sizeof(int) * m);
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	route.push_back(make_pair(0, 0));
	ans = getAnswer(0, 0) + 1;
	cout << ans;
}