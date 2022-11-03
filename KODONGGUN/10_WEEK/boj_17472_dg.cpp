#include <iostream>
#include <vector>
#include <queue> // queue, priority_queue
using namespace std;

typedef struct 
{
    int r;
    int c;
    int dir;
    int start;
} ITEM;

typedef struct 
{
    int start;
    int end;
    int distance;
} DIST_ITEM;

struct compare 
{
    bool operator() (DIST_ITEM &A, DIST_ITEM &B)
    {
        return A.distance > B.distance;
    }
};

int N, M, numOfIsland;
int p[11]; //parent, rank
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int map[10][10];
int visit[10][10];

vector<ITEM> v;
priority_queue<DIST_ITEM, vector<DIST_ITEM>, compare> pq;

void init()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i <= N; i++)
    {
        p[i] = i;
    }
}

void bfs(int r, int c)
{
    // memset(visit, 0, sizeof(int)*100);
    queue<pair<int, int>> q;
    pair<int, int> cur;
    int nr, nc;
    q.push({r, c});
    visit[r][c] = numOfIsland;
    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            nr = cur.first + dr[i];
            nc = cur.second + dc[i];
            if (0 > nr || nr >= N || 0 > nc || nc >= M) continue;
            if (visit[nr][nc]) continue;
            if (map[nr][nc])
            {
                visit[nr][nc] = numOfIsland;
                q.push({nr, nc});
            }
            else 
            {
                v.push_back({nr, nc, i, numOfIsland});
            }
        }
    }
}

void findDistance()
{
    int r, c, dir, start;
    int nr, nc, dist;
    for (auto item : v)
    {
        r = item.r; c = item.c; dir = item.dir; start = item.start;
        nr = r; nc = c; dist = 0;
        while (0 <= nr && nr < N && 0 <= nc && nc < M)
        {
            if (visit[nr][nc])
            {
                if (dist > 1)
                {
                    pq.push({start, visit[nr][nc], dist});
                }
                break;
            }

            nr += dr[dir];
            nc += dc[dir];
            dist++;
        }
    }   
}

int myFind(int A)
{
    if (p[A] == A) return A;
    p[A] = myFind(p[A]);
    return p[A];
}

void myUnion(int A, int B)
{
    A = myFind(A);
    B = myFind(B);
    if (A == B) return;
    p[B] = A;
}

pair<int,int> kruskal()
{
    int ret = 0; 
    int edge = 0;
    while(!pq.empty())
    {
        DIST_ITEM cur = pq.top();
        pq.pop();

        if (myFind(cur.start) == myFind(cur.end)) continue; 
        myUnion(cur.start, cur.end);
        ret += cur.distance;
        edge += 1;
    }

    return {ret, edge};
}

int main()
{
    init();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!map[i][j]) continue;
            if (visit[i][j]) continue;
            numOfIsland++;
            bfs(i, j);
        }
    }

    findDistance();
    pair<int, int> answer = kruskal();
    cout << ((answer.second == numOfIsland-1)?answer.first:-1) << endl;
    return 0;
}