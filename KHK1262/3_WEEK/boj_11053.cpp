#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> dp;

int main() {
	int n;

	cin >> n;
	arr.assign(n, 0);
	dp.assign(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int max_val = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
				max_val = max_val > dp[i] ? max_val : dp[i];
			}
		}
	}

	cout << max_val << endl;
}