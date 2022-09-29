#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int n, k;
stack<int> st;

int main() {
	cin >> n >> k;

	int cnt = 0;
	string s;
	vector<int> v;

	cin >> s;

	for (int j = 0; j < s.size(); j++) {

		int t = s[j] - '0';

		if (cnt < k) {
			while (!st.empty() && st.top() < t) {
				if (cnt == k) break; // cnt 다 차면 break
				cnt++;
				st.pop();
			}
		}
		st.push(t);
	}

	while (!st.empty()) { // 현재 stack 안에 순서가 반대로 들어있으므로
		v.push_back(st.top());
		st.pop();
	}

	for (int i = v.size() - 1; i >= k - cnt; i--) // 아직 남은 카운트만큼 뒷자리 자름
		cout << v[i];
}