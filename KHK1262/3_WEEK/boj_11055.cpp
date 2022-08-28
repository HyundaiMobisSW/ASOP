#include <iostream>
#include <vector>


using namespace std;

vector<int> arr;
vector<int> dp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	arr.assign(n, 0);


	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp = arr;

	int max_val = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
		max_val = max_val > dp[i] ? max_val : dp[i];
	}
	cout << max_val << endl;
}