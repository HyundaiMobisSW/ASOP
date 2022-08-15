#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int n;
int dp[1001][3];
int price[1001][3];

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) cin >> price[i][j];
	}
	dp[0][0] = price[0][0]; dp[0][1] = price[0][1]; dp[0][2] = price[0][2];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + price[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + price[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + price[i][2];
	}
	int answer = min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
	cout << answer;
}
