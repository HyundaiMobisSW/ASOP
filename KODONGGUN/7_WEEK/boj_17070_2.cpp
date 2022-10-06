/*
#include <iostream>
#include <queue>
using namespace std;

#define MAX_N 16

int N, answer;
int map[MAX_N][MAX_N];
int visit[MAX_N][MAX_N][3];

void init()
{
    cin >> N;
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            cin >> map[i][j];

}

int checkMove(int fr, int fc, int rr, int rc, int dir)
{   
    if (0 > fr || fr >= N || 0 > fc || fc >= N) return 0; 

    switch(dir)
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


int dfs(int fr, int fc, int rr, int rc, int dir)
{
    
    if (fr == N-1 && fc == N-1)
        return 1;
    
    if (visit[fr][fc][dir])
        return visit[fr][fc][dir];
    
    int ret = 0;
    switch(dir)
    {
        case 0:
        {
            // tmp = makeNextItem(cur, 0);
            if (checkMove(fr, fc + 1, fr, fc, 0))     
                ret += dfs(fr, fc + 1, fr, fc, 0);
            
            // tmp = makeNextItem(cur, 1);
            if (checkMove(fr + 1, fc + 1, fr, fc, 1))
                ret += dfs(fr + 1, fc + 1, fr, fc, 1);
        }
        break;
        case 1:
        {
            // tmp = makeNextItem(cur, 0);
            if (checkMove(fr, fc + 1, fr, fc, 0))     
                ret += dfs(fr, fc + 1, fr, fc, 0);
            
            // tmp = makeNextItem(cur, 1);
            if (checkMove(fr + 1, fc + 1, fr, fc, 1))
                ret += dfs(fr + 1, fc + 1, fr, fc, 1);

            // tmp = makeNextItem(cur, 2);
            if (checkMove(fr + 1, fc, fr, fc, 2))
                ret += dfs(fr + 1, fc, fr, fc, 2);
        }
        break;
        case 2:
        {
            // tmp = makeNextItem(cur, 1);
            if (checkMove(fr + 1, fc + 1, fr, fc, 1))
                ret += dfs(fr + 1, fc + 1, fr, fc, 1);

            // tmp = makeNextItem(cur, 2);
            if (checkMove(fr + 1, fc, fr, fc, 2))
                ret += dfs(fr + 1, fc, fr, fc, 2);
        }
        break;
    }

    visit[fr][fc][dir] = ret;
    return ret;
}

int main()
{
    
    init();
    cout << dfs(0, 1, 0, 0, 0) << endl;   
    return 0;
}
*/
