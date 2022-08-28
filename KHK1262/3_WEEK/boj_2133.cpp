#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(31, 0);

int main() {
	int n;

	dp[0] = 1;
	dp[2] = 3;

	cin >> n;

	for (int i = 4; i <= n; i+=2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j += 2) 
			dp[i] += dp[i - j] * 2;
	}

	cout << dp[n] << endl;
}