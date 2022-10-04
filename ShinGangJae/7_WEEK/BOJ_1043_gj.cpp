#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, knownPersonCnt;
int parent[51], knownPerson[51];
vector<int> party[51], knowLie;
int ans;

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

bool findParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x == y) return true;
	return false;
}

int main()
{
	cin >> n >> m;
	cin >> knownPersonCnt;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < knownPersonCnt; i++) cin >> knownPerson[i];
	for (int i = 0; i < m; i++) {
		int partyPersonCnt;
		cin >> partyPersonCnt;
		int std;
		cin >> std;
		party[i].push_back(std);
		for (int j = 0; j < partyPersonCnt - 1; j++) {
			int person;
			cin >> person;
			party[i].push_back(person);
			unionParent(std, person);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < knownPersonCnt; j++) {
			if (findParent(i, knownPerson[j])) knowLie.push_back(i);
		}
	}
	for (int i = 0; i < m; i++) {
		bool check = false;
		for (auto pers : party[i]) {
			if (find(knowLie.begin(), knowLie.end(), pers) != knowLie.end()) {
				check = true;
				break;
			}
		}
		if (!check) ans++;
	}
	cout << ans;
}