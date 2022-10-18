#include <iostream>
#include <cstring>

using namespace std;

int N, answer;
int Map[20][20];

int DFS(int y, int x, int Dir) { // Dir == 1 right, Dir == 2 Diagonal, Dir == 3 Down
	// cout << y << " " << x << "\n";
	if (y == N - 1 && x == N - 1) {
		answer += 1;
		return 0;
	}

	if(Dir == 1) {
		if (y < N && x + 1 < N && Map[y][x + 1] != 1) DFS(y, x + 1, 1); // 가로 오른쪽
		if (y + 1 < N && x + 1 < N && Map[y][x + 1] != 1 && Map[y + 1][x + 1] != 1 && Map[y + 1][x] != 1) DFS(y + 1, x + 1, 2); // 가로 대각선
	}

	if (Dir == 2) {
		if (y < N && x + 1 < N && Map[y][x + 1] != 1) DFS(y, x + 1, 1); // 가로 오른쪽
		if (y + 1 < N && x + 1 < N && Map[y][x + 1] != 1 && Map[y + 1][x + 1] != 1 && Map[y + 1][x] != 1) DFS(y + 1, x + 1, 2); // 가로 대각선
		if (y + 1 < N && x < N && Map[y + 1][x] != 1) DFS(y + 1, x, 3); // 세로 아래
	}

	if (Dir == 3) {
		if (y + 1 < N && x + 1 < N && Map[y][x + 1] != 1 && Map[y + 1][x + 1] != 1 && Map[y + 1][x] != 1) DFS(y + 1, x + 1, 2); // 가로 대각선
		if (y + 1 < N && x < N && Map[y + 1][x] != 1) DFS(y + 1, x, 3); // 세로 아래
	}
	return 0;
}


int main(void) {
	freopen("input.txt", "r", stdin);
	// fill(&Map[0][0], &Map[20][20], 1);
    //memset(Map, 1, sizeof(Map));

	
	cin >> N;
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
		}
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << Map[i][j] << " ";
		}
        cout << endl;
	}
	DFS(0, 1, 1);
	cout << answer;

	return 0;
}