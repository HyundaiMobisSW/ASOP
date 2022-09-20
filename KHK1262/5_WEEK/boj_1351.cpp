#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

//#define MAX long long int(1e12)

using namespace std;

map<long long int, long long int> dp;

//vector<long long int> dp(MAX, 0);
long long int n, p, q;


//long long int dp_func(long long int t) {
//	if (t == 0) return 1;
//	return dp_func(t / p) + dp_func(t / q);
//}


long long int dp_func(long long int t) {
	if (dp.find(t) != dp.end()) return dp[t];
	dp.insert({ t, dp_func(t / p) + dp_func(t / q) });
	return dp[t];
}


int main() {
	cin >> n >> p >> q;

	dp.insert({ 0, 1 });

	cout << dp_func(n) << endl;
}