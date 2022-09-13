#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_SIZE 32000

int visit[MAX_SIZE + 1]; // 128kb
int inDegree[MAX_SIZE + 1]; // 128kb

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adjList(N + 1);

    for (size_t i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;

        inDegree[e] += 1;
        adjList[s].push_back(e);
    }

    queue<int> q;
    vector<int> answer;
    for (size_t i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0)
        {
            visit[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        answer.push_back(cur);
        q.pop();
        for (auto adj: adjList[cur])
        {
            if (visit[adj]) continue;

            inDegree[adj] -= 1;
            if (inDegree[adj] == 0)
            {
                q.push(adj);
                visit[adj] = 1;
            }
        }    
    }

    for (auto ans: answer)
    {
        cout << ans << " ";
    }
    cout << endl;
    
    return 0;
}