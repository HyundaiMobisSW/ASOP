#include <iostream>
#include <string>
#include <queue>
using namespace std;

string map[1000];
int visit[2][1000][1000];

int main()
{
    // 1 Init
    int N, M, answer=0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> map[i];
    }
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    pair<int, int> start(0, 0), end(N - 1, M - 1);

    // 2 BFS
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(false, start));
    visit[0][start.first][start.second] = 1;
    while (!q.empty())
    {
        int opportunity = q.front().first;
        pair<int, int> cur = q.front().second;
        q.pop();
        if (cur == end)
        {
            answer = visit[opportunity][cur.first][cur.second];
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if (0 > nr || nr >= N || 0 > nc || nc >= M)
            {
                continue;
            }
            if (map[nr][nc] == '1')
            {
                if (opportunity) continue;
                if (visit[1][nr][nc]) continue;
                visit[1][nr][nc] = visit[opportunity][cur.first][cur.second] + 1;
                q.push(make_pair(1, make_pair(nr, nc)));
                
            }
            else //map[nr][nc] == '0'
            {
                if (visit[opportunity][nr][nc]) continue;
                visit[opportunity][nr][nc] = visit[opportunity][cur.first][cur.second] + 1;
                q.push(make_pair(opportunity, make_pair(nr, nc)));
            }
        }
        
    }

    // 3 answer
    cout << (answer?answer:-1) << endl;

    return 0;
}