#include <iostream>

using namespace std;

int n, dp[31];

int main()
{
	cin >> n;
	dp[2] = 3;
	for (int i = 4; i <= n; i++) {
		if (i % 2) continue;
		dp[i] = dp[i - 2] * 3;
		dp[i] += 2;
		for (int j = 0; j <= i - 4; j += 2) dp[i] += dp[j] * 2;
	}
	cout << dp[n];
}