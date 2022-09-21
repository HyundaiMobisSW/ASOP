#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(pair<int, int> p, pair<int, int> q) {
	if (p.first == q.first) return p.second > q.second;
	return p.first < q.first;
}


int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, cnt;
vector<int> dirs;

vector<pair<int, int>> standard, challenge;
vector<vector<int>> answers;

vector<pair<int, int>> getDohyong(vector<int> dir) {
	int x = 0, y = 0;
	vector<pair<int, int>> output;
	for (int i = 0; i < n; i++) {
		x += dx[dir[i] - 1];
		y += dy[dir[i] - 1];
		output.push_back(make_pair(x, y));
	}
	sort(output.begin(), output.end(), cmp);
	return output;
}

bool isSame() {
	int diffX, diffY;
	diffX = standard[0].first - challenge[0].first;
	diffY = standard[0].second - challenge[0].second;
	for (int i = 0; i < n; i++) {
		if ((standard[i].first != challenge[i].first + diffX) || (standard[i].second != challenge[i].second + diffY)) return false;
	}
	return true;
}

vector<int> getDirs() {
	int dir;
	vector<int> output;
	for (int i = 0; i < n; i++) {
		cin >> dir;
		output.push_back(dir);
	}
	//sort(output.begin(), output.end(), cmp);
	return output;
}

int main()
{
	cin >> n;
	dirs = getDirs();
	standard = getDohyong(dirs);
	cin >> cnt;
	while (cnt--) {
		dirs = getDirs();
		challenge = getDohyong(dirs);
		if (isSame()) {
			answers.push_back(dirs);
		}
	}
	cout << answers.size() << endl;
	for (int i = 0; i < answers.size(); i++) {
		for (int j = 0; j < answers[i].size(); j++) {
			cout << answers[i][j] << ' ';
		}
		cout << endl;
	}
}