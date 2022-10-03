#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

#define MAX_N 16

typedef struct item {
    pair<int, int> front;
    pair<int, int> rear;
    int dir;
} ITEM;

int N, answer;
int map[MAX_N][MAX_N];
int visit[MAX_N][MAX_N][3];

unordered_map<int, pair<int,int>> direction {
    {0, {0, 1}},     // r
    {1, {1, 1}},     // dr
    {2, {1, 0}},     // d
};


int findDirection(pair<int,int> front, pair<int,int> rear)
{
    int dr = front.first - rear.first;
    int dc = front.second - rear.second;
    if (dr == 0)
    {
        if      (dc == 1)   return 0; // { {0, 1}, 0},     // r
    }
    else if (dr == 1)
    {
        if      (dc == 1)   return 1; // { {1, 1}, 1},     // dr
        else if (dc == 0)   return 2; // { {1, 0}, 2},     // d
    }

    return -1; //error
}

void init()
{
    cin >> N;
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            cin >> map[i][j];

}

int checkMove(ITEM item)
{
    int fr, fc, rr, rc;
    fr = item.front.first;
    fc = item.front.second;
    
    if (0 > fr || fr >= N || 0 > fc || fc >= N) return 0; 

    rr = item.rear.first;
    rc = item.rear.second;

    switch(item.dir)
    {
        case 0: case 2:
        {
            if (map[fr][fc]) return 0;
        }
        case 1:
        {
            if (map[fr][fc] || map[fr][rc] || map[rr][fc]) return 0;

        }
    }
    return 1;
}

ITEM makeNextItem(ITEM cur, int dir)
{
    return {
        {
            cur.front.first + direction[dir].first,
            cur.front.second + direction[dir].second
        },
        {
            cur.front.first,
            cur.front.second
        },
        dir, 
    };
}

int dfs(ITEM cur)
{
    if (cur.front.first == N-1 && cur.front.second == N-1)
        return 1;
    
    if (visit[cur.front.first][cur.front.second][cur.dir])
        return visit[cur.front.first][cur.front.second][cur.dir];
    

    ITEM tmp;
    int ret = 0;
    switch(cur.dir)
    {
        case 0:
        {
            tmp = makeNextItem(cur, 0);
            if (checkMove(tmp))     ret += dfs(tmp);
            
            tmp = makeNextItem(cur, 1);
            if (checkMove(tmp))     ret += dfs(tmp);
        }
        break;
        case 1:
        {
            tmp = makeNextItem(cur, 0);
            if (checkMove(tmp))     ret += dfs(tmp);
            
            tmp = makeNextItem(cur, 1);
            if (checkMove(tmp))     ret += dfs(tmp);

            tmp = makeNextItem(cur, 2);
            if (checkMove(tmp))     ret += dfs(tmp);
        }
        break;
        case 2:
        {
            tmp = makeNextItem(cur, 1);
            if (checkMove(tmp))     ret += dfs(tmp);
            
            tmp = makeNextItem(cur, 2);
            if (checkMove(tmp))      ret += dfs(tmp);
        }
        break;
    }

    visit[cur.front.first][cur.front.second][cur.dir] = ret;
    return ret;
}

int main()
{
    init();
    cout << dfs({{0,1}, {0,0}, 0}) << endl;   
    return 0;
}