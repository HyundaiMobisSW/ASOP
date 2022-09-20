#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologySort(vector<int>& inDegree, vector<vector<int>>& a, int n) {
	vector<int> result(n + 1, 0);
	queue<int> q;


	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}


	for (int i = 1; i <= n; i++) {
		if (q.empty()) 
			return;
		
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}


	for (int i = 1; i <= n; i++) {
		printf("%d ", result[i]);
	}
}

int main(void) {
	int n, m;

	cin >> n >> m;
	vector<vector<int>> a(n + 1);
	vector<int> indegree(n + 1, 0);


	for (int i = 0; i < m; i++) {
		int v, w;
		cin >> v >> w;
		a[v].push_back(w);
		++indegree[w];
	}

	topologySort(indegree, a, n);
}