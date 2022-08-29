#include <iostream>
#define max(a, b) (a > b ? a : b)

using namespace std;

int n, ans, a[1001], dp[1001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	ans = dp[0] = a[0];
	for (int i = 1; i < n; i++) {
		dp[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[j] >= a[i]) continue;
			dp[i] = max(dp[i], dp[j] + a[i]);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
}