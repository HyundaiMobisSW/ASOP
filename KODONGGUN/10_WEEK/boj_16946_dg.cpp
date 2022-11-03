#include <iostream>
#include <queue>
#include <unordered_set>

#define MAX 1000
using namespace std;


int map[MAX][MAX];
int visit[MAX][MAX];
int answer[MAX][MAX];
int area_num[MAX][MAX]; // area_num[r][c]
int area_max[MAX * MAX]; // area_max[area_num[r][c]]

int dr[4] = {-1,0,1,0};
int dc[4] = {0,-1,0,1};

int N, M, area_cnt;

void init()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            char tmp;
            cin >> tmp;
            map[i][j] = tmp - '0';
        }
    }
}

void printAnswer()
{
    // cout << endl;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cout << answer[i][j];
        }
        cout << endl;
    }
}

void bfs(int r, int c)
{
    queue<pair<int,int>> q;
    q.push({r, c});
    int cnt = 0;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        if (visit[cur.first][cur.second]) continue;
        visit[cur.first][cur.second] = 1;
        area_num[cur.first][cur.second] = area_cnt;
        cnt++;
        for (size_t i = 0; i < 4; i++)
        {
            int nr, nc;
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            
            if (0 > nr || nr >= N || 0 > nc || nc >= M)
                continue;
            if (map[nr][nc] == 1)
                continue;
            q.push({nr, nc});
        }
    }
    area_max[area_cnt] = cnt;
}

void findArea()
{
    int cnt = 0;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if (map[i][j]) continue;
            if (visit[i][j]) continue;
            bfs(i, j);
            area_cnt++;
        }        
    }
}

void findAnswer()
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if (map[i][j])
            {
                unordered_set<int> v; // visit
                for (size_t k = 0; k < 4; k++)
                {
                    int nr, nc;
                    nr = i + dr[k];
                    nc = j + dc[k];
                    
                    if (0 > nr || nr >= N || 0 > nc || nc >= M)
                        continue;
                    if (map[nr][nc] == 1)
                        continue;
                    if (v.count(area_num[nr][nc])) continue;
                    v.insert(area_num[nr][nc]);
                    answer[i][j] += area_max[area_num[nr][nc]];
                }
                answer[i][j] = (answer[i][j] + 1) % 10;

            }
        }        
    }
}

int main()
{
    init();
    findArea();
    findAnswer();
    printAnswer();

    return 0;
}