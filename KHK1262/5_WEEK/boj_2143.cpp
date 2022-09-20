#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1001

using namespace std;

int A[MAX];
int B[MAX];

vector<long long int> A_sum;
vector<long long int> B_sum;

long long int t;

int n, m;

int b_left_search(int s, int e, long long int target) {
	while (s + 1 < e) {
		int mid = (s + e) / 2;
		if (B_sum[mid] >= target) e = mid;
		else s = mid;
	}
	return e;
}

int b_right_search(int s, int e, long long int target) {
	while (s + 1 < e) {
		int mid = (s + e) / 2;
		if (B_sum[mid] > target) e = mid;
		else s = mid;
	}
	return e;
}


int main() {
	cin >> t;
	cin >> n;

	int temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		A[i] = A[i - 1] + temp;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			A_sum.push_back(A[i] - A[j]);
		}
	}

	cin >> m;

	for (int i = 1; i <= m; i++) {
		cin >> temp;
		B[i] = B[i - 1] + temp;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < i; j++) {
			B_sum.push_back(B[i] - B[j]);
		}
	}

	//for (int i = 0; i < A_sum.size(); i++) {
	//	for (int j = 0; j < B_sum.size(); j++) {
	//		if (A_sum[i] + B_sum[j] == t) cnt++;
	//	}
	//}
	sort(A_sum.begin(), A_sum.end());
	sort(B_sum.begin(), B_sum.end());

	long long int cnt = 0;

	for (int i = 0; i < A_sum.size(); i++) {
		int low = b_left_search(-1, B_sum.size(), t - A_sum[i]);
		int high = b_right_search(-1, B_sum.size(), t - A_sum[i]);
		//cout << t - A_sum[i] << " " << low << "  " << high << endl;
		cnt += (high - low);
	}

	cout << cnt << endl;
}