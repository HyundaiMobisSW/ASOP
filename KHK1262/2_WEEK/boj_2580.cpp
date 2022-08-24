#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

using P = pair<int, int>;

vector<P> pos;

vector<vector<bool>> row(9, vector<bool>(9, false));
vector<vector<bool>> col(9, vector<bool>(9, false));
vector<vector<bool>> small(9, vector<bool>(9, false));

vector<vector<int>> graph(9, vector<int>(9));

bool finish = false;

bool isPromising(int y, int x, int num) {
	if (row[y][num]) return false;
	if (col[x][num]) return false;
	if (small[y / 3 * 3 + x / 3][num]) return false;
	return true;
}


void back_track(int idx) {
	if (idx == pos.size()) {
		for (auto v : graph) {
			for (auto t : v) {
				cout << t << " ";
			}
			cout << endl;
		}
		//exit(0);
		finish = true;
		return;
	}
	int y = pos[idx].first;
	int x = pos[idx].second;

	for (int i = 1; i <= 9; i++) {
		if (isPromising(y, x, i - 1)) {
			row[y][i - 1] = true;
			col[x][i - 1] = true;
			small[y / 3 * 3 + x / 3][i - 1] = true;

			graph[y][x] = i;
			back_track(idx + 1);

			graph[y][x] = 0;
			row[y][i - 1] = false;
			col[x][i - 1] = false;
			small[y / 3 * 3 + x / 3][i - 1] = false;
		}
		if (finish) return;
	}
}


int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> graph[i][j];

			if (graph[i][j] == 0) pos.push_back({ i, j });
			else {
				row[i][graph[i][j] - 1] = true;
				col[j][graph[i][j] - 1] = true;
				small[i / 3 * 3 + j / 3][graph[i][j] - 1] = true;
			}
		}
	}
	back_track(0);
}