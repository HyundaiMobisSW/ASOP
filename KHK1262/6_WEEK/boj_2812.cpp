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
				if (cnt == k) break; // cnt �� ���� break
				cnt++;
				st.pop();
			}
		}
		st.push(t);
	}

	while (!st.empty()) { // ���� stack �ȿ� ������ �ݴ�� ��������Ƿ�
		v.push_back(st.top());
		st.pop();
	}

	for (int i = v.size() - 1; i >= k - cnt; i--) // ���� ���� ī��Ʈ��ŭ ���ڸ� �ڸ�
		cout << v[i];
}