#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

#define max(a, b) (a > b ? a : b)

using namespace std;

int v, dist, endVer;
vector<pair<int, int>> tree[100001];
bool visit[100001];

void getEndPoint(int curVer, int curDist) {
	if (dist < curDist) {
		endVer = curVer;
		dist = curDist;
	}
	for (auto tr : tree[curVer]) {
		if (visit[tr.first]) continue;
		visit[tr.first] = true;
		getEndPoint(tr.first, curDist + tr.second);
		visit[tr.first] = false;
	}
}

//한 번 = 끝 점
//두번째 = 지름 구하기

int main()
{
	cin >> v;
	for (int i = 1; i <= v; i++) {
		int cur;
		bool even = true;
		cin >> cur;
		while (true) {
			int ver, edge;
			cin >> ver;
			if (ver == -1)break;
			cin >> edge;
			tree[cur].push_back(make_pair(ver, edge));
		}
	}
	visit[1] = true;
	getEndPoint(1, 0);
	dist = 0;
	memset(visit, false, sizeof(bool) * (v + 1));
	visit[endVer] = true;
	getEndPoint(endVer, 0);
	cout << dist;
}