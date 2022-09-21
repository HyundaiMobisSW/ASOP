#include <iostream>
#include <map>

using namespace std;

long long n, p, q;
map<long long, long long> dp;

long long getAnswer(long long input) {
	if (input == 1) return 2;
	if (input == 0) return 1;
	if (dp.find(input) != dp.end()) return dp[input];
	dp[input] = getAnswer(input / p) + getAnswer(input / q);
	return dp[input];
}

int main()
{
	cin >> n >> p >> q;
	long long ans = getAnswer(n);
	cout << ans;
}