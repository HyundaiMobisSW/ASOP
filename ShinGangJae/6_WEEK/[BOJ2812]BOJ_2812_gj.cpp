#include <iostream>
#include <string>

using namespace std;

int n, k, cnt, tmp;
string num;
string answer;

int main()
{
	cin >> n >> k;
	cin >> num;
	for (int i = 0; i < n; i++) {
		if (!answer.length()) {
			answer += num[i];
			continue;
		}
		if (answer[answer.length() - 1] >= num[i]) answer += num[i];
		else {
			while (answer.length()) {
				if ((cnt >= k) || (answer[answer.length() - 1] >= num[i])) break;
				cnt++;
				answer.erase(answer.length() - 1, 1);
			}
			answer += num[i];
		}
		if (cnt >= k) {
			answer += num.substr(i + 1, n - i);
			break;
		}
	}
	if(cnt < k) answer = answer.substr(0, n - k);
	cout << answer;
}