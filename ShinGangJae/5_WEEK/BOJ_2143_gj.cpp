#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int t, n, m;
vector<int> A, B, AllA, AllB;
map<int, int> eleCnt;
long ans;

vector<int> getSumTable(int cnt) {
	vector<int> output;
	int tmp = 0, num;
	while (cnt--) {
		cin >> num;
		tmp += num;
		output.push_back(tmp);
	}
	return output;
}

vector<int> getAllSums(vector<int>input) {
	vector<int> output;
	for (int i = 0; i < input.size(); i++) {
		output.push_back(input[i]);
		for (int j = i + 1; j < input.size(); j++) {
			output.push_back(input[j] - input[i]);
		}
	}
	return output;
}

map<int, int> transMap(vector<int> input) {
	map<int, int> output;
	for (auto in : input) {
		auto it = output.find(in);
		if (it == output.end()) output[in] = 1;
		else output[in]++;
	}
	return output;
}

int main()
{
	cin >> t;
	cin >> n;
	A = getSumTable(n);
	cin >> m;
	B = getSumTable(m);
	AllA = getAllSums(A);
	AllB = getAllSums(B);
	eleCnt = transMap(AllB);
	for (auto in : AllA) {
		if (eleCnt.find(t - in) == eleCnt.end()) continue;
		ans += eleCnt[t - in];
	}
	cout << ans;
}