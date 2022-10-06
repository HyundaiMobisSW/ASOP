#include <string>
#include <vector>
#include <queue>
#include <algorithm> // max
using namespace std;

int bfs(int start, int size, const vector<vector<int>>& adj_list)
{
    int max_dist = 0;
    vector<int> visit(size+1, 0);
    
    queue<int> q;
    q.push(start);
    
    visit[start] = 1;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (auto adj: adj_list[cur])
        {
            if (visit[adj]) continue;
            visit[adj] = visit[cur] + 1;
            max_dist = max(max_dist, visit[adj]);
            q.push(adj);
        }
    }
    
    int ret = 0;
    for (auto v:visit)
    {
        if (v == max_dist) ret++;
    }
    return ret;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> adj_list(n+1);
    for (auto edg:edge) 
    {
        adj_list[edg[0]].push_back(edg[1]);
        adj_list[edg[1]].push_back(edg[0]);
    }
    
    answer = bfs(1, n, adj_list);
    return answer;
}

int main()
{
    int n = 6;
    vector<vector<int>> edge = {{3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2}};
    int answer = 3;
    int ret = solution(n, edge);
    cout << (ret == answer) << endl;
    return 0;
}