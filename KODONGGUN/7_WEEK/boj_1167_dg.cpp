#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // memset
using namespace std;

#define V_MAX 100001

int V;
vector<vector<pair<int,int>>> G;

void init()
{
    cin >> V;
    for (size_t i = 0; i < V+1; i++)
    {
        G.push_back(vector<pair<int,int>>());
    }
    
    for (size_t i = 0; i < V; i++)
    {
        int s;
        cin >> s;
        while (1)
        {
            int e, w;
            cin >> e;
            if (e == -1) break;
            cin >> w;
            G[s].push_back({e, w});
        }
    }

}

pair<int,int> bfs(pair<int,int> start) // start = { node, weight = 0}
{
    pair<int,int> ret = {-1, -1};

    queue<pair<int, int>> q;
    q.push(start);

    int visit[V_MAX];
    memset(visit, 0, sizeof(int) * V_MAX);

    while (!q.empty())
    {
        pair<int, int> cur;
        cur = q.front();
        q.pop();
        if (visit[cur.first]) continue;
        visit[cur.first] = 1;
        
        if (cur.second > ret.second)
        {
            ret.first = cur.first;
            ret.second = cur.second;
        }

        for (auto adj: G[cur.first])
        {
            q.push({adj.first, adj.second + cur.second});
        }
        
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();

    // 그래프 탐색 두번
    // 1. 아무 노드에서 시작해서 가장 먼노드까지 간 다음, 
    pair<int,int> tmp;
    tmp = bfs({1, 0});
    
    // 2. 가장 먼노드 노드에서 가장 먼노드까지 탐색
    tmp = bfs({tmp.first, 0});
    cout << tmp.second << endl;
    return 0;
}