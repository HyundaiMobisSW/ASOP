#include <iostream>
#include <algorithm> // max
#include <vector>
#include <unordered_set>
using namespace std;

int N, ans1, ans2;
int board[10][10];
int visit[10][10];
vector<pair<int,int>> poss;

void init()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j])
            {
                poss.push_back({i, j});
            }
        }
    }
    // printV(poss);
}

bool diagonalCheck(int r, int c)
{
    int nr, nc;
    nr = r - 1;
    nc = c - 1;
    while (nr >= 0 && nc >= 0)
    {
        if (visit[nr][nc]) return true;
        nr -= 1;
        nc -= 1;
    }

    nr = r - 1;
    nc = c + 1;
    while (nr >= 0 && nc < N)
    {
        if (visit[nr][nc]) return true;
        nr -= 1;
        nc += 1;
    }
    
    return false;
}

void backtrack(int ind, int cnt, int color)
{   
    for (size_t i = ind; i < poss.size(); i++)
    {
        if (visit[poss[i].first][poss[i].second]) 
            continue;
        
        if ((poss[i].first + poss[i].second) % 2 == color) 
            continue;

        if (diagonalCheck(poss[i].first, poss[i].second)) 
            continue;
        
        visit[poss[i].first][poss[i].second] = 1;
        if (color)
            ans1 = max(ans1, cnt+1);
        else
            ans2 = max(ans2, cnt+1);
        backtrack(i + 1, cnt + 1, color);
        visit[poss[i].first][poss[i].second] = 0;
    }
    
}

int main()
{
    init();
    backtrack(0, 0, 0);
    backtrack(0, 0, 1);
    cout << ans1 + ans2 << endl;
    return 0;
}