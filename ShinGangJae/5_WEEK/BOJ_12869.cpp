#include <iostream>
#include <memory.h>

#define min(a, b) (a < b ? a : b)

using namespace std;

int demage[3] = { 9, 3, 1 };
int dp[61][61][61], scv[3];
int n, ans;

int getAnswer(int first, int second, int third) {
	if ((first >= scv[0]) && (second >= scv[1]) && (third >= scv[2])) return 0;
	first = min(first, scv[0]); second = min(second, scv[1]); third = min(third, scv[2]);
	if (dp[first][second][third] != -1) return dp[first][second][third];
	dp[first][second][third] = 9999;
	dp[first][second][third] = min(getAnswer(first + 9, second + 3, third + 1) + 1, dp[first][second][third]);
	dp[first][second][third] = min(getAnswer(first + 9, second + 1, third + 3) + 1, dp[first][second][third]);
	dp[first][second][third] = min(getAnswer(first + 3, second + 9, third + 1) + 1, dp[first][second][third]);
	dp[first][second][third] = min(getAnswer(first + 3, second + 1, third + 9) + 1, dp[first][second][third]);
	dp[first][second][third] = min(getAnswer(first + 1, second + 3, third + 9) + 1, dp[first][second][third]);
	dp[first][second][third] = min(getAnswer(first + 1, second + 9, third + 3) + 1, dp[first][second][third]);
	return dp[first][second][third];
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) cin >> scv[i];
	ans = getAnswer(0, 0, 0);
	cout << ans;
}