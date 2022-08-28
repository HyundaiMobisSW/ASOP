#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using P = pair<int, int>;

vector<P> arr;
vector<vector<int>> dp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, k;

	cin >> n >> k;

	dp.assign(n + 1, vector<int>(k + 1, 0));
	arr.push_back({ 0,0 });


	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;
		arr.push_back({ w, v });
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= arr[i].first) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].first] + arr[i].second);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k] << endl;

}