#include <iostream>
#include <queue>
#include <memory.h>

#define TIME 1000000000

using namespace std;

typedef struct inform {
	int time, way, idx;
}inform;

int n, t;
char w;
queue<inform> totalCar;
queue<int> wayCar[4];
int ans[200001];

void solve() {
	int cnt = 0;
	int curTime = totalCar.front().time;
	while (cnt < n) {
		//현재 시간 초기화와 현재시간에 따른 차로별 차량 상태 초기화
		if (!totalCar.empty()) {
			while (curTime >= totalCar.front().time) {
				wayCar[totalCar.front().way].push(totalCar.front().idx);
				totalCar.pop();
				if (totalCar.empty()) break;
			}
			if ((wayCar[0].empty() & wayCar[1].empty() & wayCar[2].empty())) curTime = totalCar.front().time - 1;
		}
		//각 차로에서 나가야하는 차들 판별 각 차로당 1초에 하나씩
		int out[4];
		int isEnd = 0;
		memset(out, -1, sizeof(int) * 4);
		for (int i = 0; i < 4; i++) {
			if (wayCar[i].empty()) continue;
			if (wayCar[(i + 3) % 4].empty()) {
				out[i] = wayCar[i].front();
			}
			else isEnd++;
		}
		if (isEnd == 4) break;
		for (int i = 0; i < 4; i++) {
			if (out[i] != -1) {
				ans[out[i]] = curTime;
				wayCar[i].pop();
				cnt++;
			}
		}
		curTime++;
	}
}

int main() {
	cin >> n;
	memset(ans, -1, sizeof(int) * (n + 1));
	for (int i = 0; i < n; i++) {
		cin >> t >> w;
		totalCar.push({ t, w - 'A', i });
	}
	solve();
	for (int i = 0; i < n; i++) cout << ans[i] << '\n';
	return 0;
}