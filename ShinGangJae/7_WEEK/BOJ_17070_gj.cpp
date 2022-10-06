#include <iostream>
#include <memory.h>

using namespace std;

int n;
int dp[17][17][17][17], map[17][17];

int getAnswer(int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	if ((x2 > n) || (y2 > n)) return 0;
	if ((x2 == n) && (y2 == n)) {
		return 1;
	}
	if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
	dp[x1][y1][x2][y2] = 0;
	if ((dx > 0) && (dy > 0)) {
		if (!map[y2][x2 + 1])	dp[x1][y1][x2][y2] += getAnswer(x2, y2, x2 + 1, y2);
		if(!map[y2+1][x2])	dp[x1][y1][x2][y2] += getAnswer(x2, y2, x2 , y2 + 1);
		if (!map[y2 + 1][x2 + 1] && !map[y2][x2 + 1] && !map[y2 + 1][x2]) {
			dp[x1][y1][x2][y2] += getAnswer(x2, y2, x2 + 1, y2 + 1);
		}	
	}
	else if ((dx > 0) && (dy <= 0)) {
		if(!map[y2][x2+1])	dp[x1][y1][x2][y2] += getAnswer(x2, y2, x2 + 1, y2);
		if (!map[y2 + 1][x2 + 1] && !map[y2][x2 + 1] && !map[y2 + 1][x2]) {
			dp[x1][y1][x2][y2] += getAnswer(x2, y2, x2 + 1, y2 + 1);
		}
	}
	else if ((dx <= 0) && (dy > 0)) {
		if(!map[y2+1][x2])	dp[x1][y1][x2][y2] += getAnswer(x2, y2, x2, y2 + 1);
		if (!map[y2 + 1][x2 + 1] && !map[y2][x2 + 1] && !map[y2 + 1][x2]) {
			dp[x1][y1][x2][y2] += getAnswer(x2, y2, x2 + 1, y2 + 1);
		}
	}
	return dp[x1][y1][x2][y2];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	int ans = getAnswer(1, 1, 2, 1);
	cout << ans;
}