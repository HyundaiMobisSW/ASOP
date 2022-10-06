#include <iostream>
#include <vector>
#include <queue> // priority queue

using namespace std;

#define N_MAX 1001

int N, M;
int visit[N_MAX];
vector<vector<pair<int,int>>> adj_list;

void init()
{
    cin >> N;
    cin >> M;
    adj_list.reserve(N+1);
    int s,e,w;
    for (size_t i = 0; i < M; i++)
    {
        cin >> s >> e >> w;
        adj_list[s].push_back({e, w});
        adj_list[e].push_back({s, w});
    }
}

int prim()
{
    int ret = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        pair<int,int> cur = pq.top();
        pq.pop();

        if (visit[cur.second]) continue;
        visit[cur.second] = 1;
        ret += (-cur.first); // default sorting by max value

        for (auto adj: adj_list[cur.second])
        {
            pq.push({-adj.second, adj.first}); // default sorting by max value
        }

    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    cout << prim() << endl;
    return 0;
}