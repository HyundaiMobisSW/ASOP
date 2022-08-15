#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>

#define INF 100000001
#define min(a, b) (a < b ? a : b)

using namespace std;

int n, m, depart, arrive;
int city[1001][1001];
int dist[1001];

struct cmp {
	bool operator()(pair<int, int> p, pair<int, int> q) {
		return p.second > q.second;
	}
};

void solve() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
	q.push(make_pair(depart, 0));
	while (!q.empty()) {
		pair<int, int> p = q.top();
		int cur = p.first;
		int cost = p.second;
		q.pop();
		if (dist[cur] < cost) continue;
		for (int i = 1; i <= n; i++) {
			if (dist[i] > cost + city[cur][i]) {
				dist[i] = cost + city[cur][i];
				q.push(make_pair(i, dist[i]));
			}
		}
	}
	
}

int main()
{
	cin >> n >> m;
	fill(dist, dist + n + 1, INF);
	fill(city[0], city[n + 1], INF);
	while (m--) {
		int cost;
		cin >> depart >> arrive >> cost;
		city[depart][arrive] = min(city[depart][arrive], cost);
	}
	for (int i = 0; i <= n; i++) city[i][i] = 0;
	cin >> depart >> arrive;
	solve();
	cout << dist[arrive];
}