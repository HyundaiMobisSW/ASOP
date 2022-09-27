#include <iostream>
#include <queue>

using namespace std;

priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int answer[500001], n, top[500001];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> top[i];
	}
	for (int i = n; i > 0; i--) {
		pq.push(make_pair(top[i], i));
		while (pq.top().first < top[i]) {
			answer[pq.top().second] = i;
			pq.pop();
		}
	}
	for (int i = 1; i <= n; i++) cout << answer[i] << ' ';
}