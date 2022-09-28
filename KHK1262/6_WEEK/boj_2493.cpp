#include<iostream>
#include <stack>

using namespace std;

struct node
{
	int num;
	int pos;
};

int n;
stack<node> st;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		while (!st.empty()) {
			if (st.top().num > temp) {
				cout << st.top().pos << " ";
				break;
			}
			st.pop();
		}
		if (st.empty()) cout << 0 << " ";
		st.push(node{ temp, i + 1 });
	}
}