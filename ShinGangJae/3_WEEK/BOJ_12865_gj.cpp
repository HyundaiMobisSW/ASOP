#include <iostream>
#include <memory.h>
#define max(a, b) (a > b ? a : b)
using namespace std;

int dp[100001][101], item[101][2];
int n, k;

/*
//dp의 index값을 현재 들 수 있는 무게, 담기는 값을 값 어치일 경우
//문제점 같은 weight 값을 가진 물품이 있을 때 문제가 생김
//반례
3 6
6 15
3 10
3 20
output : 40
정답 : 30
//해결 방안? 2차원 배열로 풀기
int getAnswer(int weight) {
	if (weight < 0) return 0;
	if (dp[weight] != -1) return dp[weight];
	dp[weight] = 0;
	for (int i = 0; i < n; i++) {
		if (weight < item[i][0]) continue;
		dp[weight] = max(dp[weight], getAnswer(weight - item[i][0]) + item[i][1]);
	}
	return dp[weight];
}
*/
// getAnswer 매개변수 weight : 앞으로 들 수 있는 무게, idx : 물품 번호
// dp 저장 값 : weight 무게 만큼 들 수 있고 idx를 들었을 때 가장 큰 값
int getAnswer(int weight, int idx) {
	if (idx < 0) return 0;
	if (dp[weight][idx] != -1) return dp[weight][idx];
	dp[weight][idx] = getAnswer(weight, idx - 1);
	if (weight - item[idx][0] >= 0) {
		dp[weight][idx] = max(dp[weight][idx], getAnswer(weight - item[idx][0], idx - 1) + item[idx][1]);
	}
	return dp[weight][idx];
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < k + 2; i++) memset(dp[i], -1, sizeof(int) * (n + 1));
	for (int i = 0; i < n; i++) {
		cin >> item[i][0] >> item[i][1];
	}
	int ans = getAnswer(k, n - 1);
	cout << ans;
}