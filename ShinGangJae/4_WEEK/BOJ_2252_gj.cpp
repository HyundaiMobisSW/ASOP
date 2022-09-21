#include <iostream>
#include <queue>

using namespace std;

//위상정렬
//1. 진입 차수가 0인 정점을 큐에 삽입
//2. 큐에서 원소를 꺼내 연결된 모든 간선을 제거
//3. 간선 제거 이후에 진입차수가 0이 된 정점을 큐에 삽입
//4. 큐가 빌때까지 2~3번 반복 모든 원소 방문 전에 큐가 비면 사이클 존재

int n, m;
queue<int> q;
vector<int> map[32001], result;
int Degrees[32001];

//1. 진입 차수가 0인 정점을 큐에 삽입
void putZeroDegree() {
	for (int i = 1; i <= n; i++) {
		if (!Degrees[i]) q.push(i);
	}
}

//2. 큐에서 원소를 꺼내 연결된 모든 간선을 제거
void eraseEdges() {
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		result.push_back(cur);
		for (int j = 0; j < map[cur].size(); j++) {
			int connected = map[cur][j];
			Degrees[connected]--;
			if (!Degrees[connected]) q.push(connected);
		}
	}
}
int main()
{
	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		Degrees[b]++;
	}
	putZeroDegree();
	eraseEdges();
	for (auto output : result) cout << output << ' ';
}