#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N, M;
int arr[1000][1000];
int visit[1000][1000][2];

queue<pair<pair<int, int>, pair<int, int>>> q;
string temp;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int BFS(){
    visit[0][0][0] = 1;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int b = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();
        if(x == N - 1 && y == M - 1) return cnt;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && yy >= 0 && xx < N && yy < M){
                if(arr[xx][yy] == 1 && b == 0){
                    visit[xx][yy][b+1] = 1;
                    q.push(make_pair(make_pair(xx, yy), make_pair(b+1, cnt+1)));
                }
                else if(arr[xx][yy] == 0 && visit[xx][yy][b] == 0){
                    visit[xx][yy][b] = 1;
                    q.push(make_pair(make_pair(xx, yy), make_pair(b, cnt+1)));
                }
            }
        }
    }

    return -1;

}


int main(void){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> temp;

        // for(int j = 0; j < M; j++){
        //     arr[i][j] = temp[j] - '0';
        // }
    }

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < M; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << BFS();
    return 0;
}