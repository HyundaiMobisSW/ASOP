#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct graph {
	int cost, source, dest;
}graph;

bool cmp(graph a, graph b) {
	return a.cost < b.cost;
}

int n, m, ans;
vector<graph> g;
int parent[1001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

bool find(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x == y) return true;
	return false;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int source, dest, cost;
		cin >> source >> dest >> cost;
		g.push_back({ cost, source, dest });
	}
	sort(g.begin(), g.end(), cmp);
	for (int i = 0; i <= n; i++) parent[i] = i;
	for (auto gg : g) {
		if (find(gg.source, gg.dest)) continue;
		ans += gg.cost;
		unionParent(gg.source, gg.dest);
	}
	cout << ans;
}