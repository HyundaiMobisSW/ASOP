#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int N, M;
int arr[50][50];
int visit[50][50];
int DP[50][50] = {-1};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string str;
int MAX;

// 시계 방향 순으로 이동
int DFS(int y, int x){
    if(y < 0 || y >= N || x < 0 || x >= M || arr[y][x] == 0){
        return 0;
    }
    if(visit[y][x] == 1){
        cout << -1;
        exit(0);
    }
    if(DP[y][x] != -1) return DP[y][x];

    visit[y][x] = 1;
    DP[y][x] = 0;

    for(int i = 0; i < 4; i++){
        int yy = y + arr[y][x] * dy[i];
        int xx = x + arr[y][x] * dx[i];
        DP[y][x] = max(DP[y][x], DFS(yy, xx) + 1);
    }
    visit[y][x] = 0;

    return DP[y][x];
}
int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(int j = 0; j < M; j++){
            if(str[j] == 'H') arr[i][j] = 0;
            else arr[i][j] = str[j] - '0';
        }
    }
    memset(DP, -1, sizeof(DP));
    cout << DFS(0, 0);


    return 0;
}