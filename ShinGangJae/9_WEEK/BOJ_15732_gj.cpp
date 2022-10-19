#include <iostream>
#define min(a, b) (a < b ? a : b)
using namespace std;

int n, k, d, ans;
int cmd[10001][3];

int main()
{
	cin >> n >> k >> d;
	for (int i = 0; i < k; i++) cin >> cmd[i][0] >> cmd[i][1] >> cmd[i][2];
	int lo = 0, hi = n;
	while (lo <= hi) {
		long long cnt = 0;
		int mid = (lo + hi) / 2;
		for (int i = 0; i < k; i++) {
			if (mid < cmd[i][0]) continue;
			if (mid < cmd[i][1]) cnt += (mid - cmd[i][0]) / cmd[i][2] + 1;
			else cnt += (cmd[i][1] - cmd[i][0]) / cmd[i][2] + 1;
			/*
			int tmp = cmd[i][0];
			while ((tmp <= mid) && (tmp <= cmd[i][1])) {
				tmp += cmd[i][2];
				cnt++;
			}
			*/
		}
		if (cnt < d) lo = mid + 1;
		else {
			ans = mid;
			hi = mid - 1;
		}
	}
	cout << ans;
}