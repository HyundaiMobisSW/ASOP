#include <iostream>
#include <string>
#include <cstring> // memset
#include <algorithm> // max
using namespace std;

#define MAX 50

struct pos {
    int r;
    int c;
};


int N, M;
string board[MAX];
int visit[MAX][MAX];
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

int memo[MAX][MAX];

void init();
int dfs(pos cur);
void printArrayDP();

int main()
{
    init();
    
    cout << dfs({0,0}) << endl;;

    return 0;
}


void init()
{
    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    memset(visit, 0, sizeof(int) * N * M);
    memset(memo, 0, sizeof(int) * N * M);
}

void printArrayDP()
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cout << memo[i][j];
        }
        cout << endl;
    }
}

int dfs(pos cur)
{
    if (memo[cur.r][cur.c]) return memo[cur.r][cur.c];

    if (board[cur.r][cur.c] == 'H') return 0;
    
    visit[cur.r][cur.c] = 1;
    
    int dist = board[cur.r][cur.c] - '0';
    int ret = 0;
    int max_ret = 0;

    for (size_t i = 0; i < 4; i++)
    {
        int nr = cur.r + dr[i] * dist;
        int nc = cur.c + dc[i] * dist;

        if (0 > nr || nr >= N || 0 > nc || nc >= M) continue;
        if (visit[nr][nc]) return -1;

        ret = dfs({nr, nc});
        if (ret == -1) break;
        max_ret = max(max_ret, ret);
    }
    memo[cur.r][cur.c] = max(memo[cur.r][cur.c], max_ret + 1);

    visit[cur.r][cur.c] = 0;

    if (ret == -1) return -1;
    return memo[cur.r][cur.c];
}