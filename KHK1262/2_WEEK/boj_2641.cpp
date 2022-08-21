#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	
	int n, t, cnt=0;

	cin >> n;

	string s;
	string r_s;
	vector<string> answer;

	for (int i = 0; i < n; i++) {

		char t;
		cin >> t;
		s += t;

		if (t == '1') r_s += '3';
		else if (t == '2') r_s += '4';
		else if (t == '3') r_s += '1';
		else r_s += '2';
	}

	reverse(r_s.begin(), r_s.end());

	cin >> t;

	for (int i = 0; i < t; i++) {
		string temp = "";

		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			temp += c;
		}
		string temp_2 = temp;

		for (int i = 0; i < n; i++) {
			if (temp_2 == s || temp_2 == r_s) {
				answer.push_back(temp);
				cnt++;
				break;
			}

			temp_2 = temp_2.substr(1, n-1) + temp_2[0];
		}
	}


	cout << cnt << endl;

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < n; j++) {
			cout << answer[i][j];
			cout << " ";
		}
		cout << endl;

	}
}