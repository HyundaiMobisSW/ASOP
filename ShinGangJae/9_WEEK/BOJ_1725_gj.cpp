#include <iostream>
#include <vector>
#define max(a, b)(a > b ? a : b)
#define min(a, b)(a < b ? a : b)
using namespace std;

long long ans;
vector<int> hist;
int n;

int solve(int left, int right) {
	if (left == right) return hist[left];
	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve(mid + 1, right));
	int lo = mid, hi = mid + 1;
	int height = min(hist[lo], hist[hi]);
	ret = max(ret, height * 2);
	while (left < lo || hi < right) {
		if (hi < right && (lo == left || hist[lo - 1] < hist[hi + 1])) {
			++hi;
			height = min(height, hist[hi]);
		}
		else {
			--lo;
			height = min(height, hist[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}

int main() {
	cin >> n;
	hist.assign(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> hist[i];
	}
	ans = solve(0, n);
	cout << ans;
}