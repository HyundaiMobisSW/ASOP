#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_SIZE 32000

int visit[MAX_SIZE + 1]; // 128kb
vector<int> answer;

void dfs(int index, const vector<vector<int>>& adjList)
{
    visit[index] = 1;
    for (auto adj: adjList[index])
    {
        if (visit[adj]) continue;
        dfs(adj, adjList);
    }
    answer.push_back(index);
    
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adjList(N + 1);

    for (size_t i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        adjList[s].push_back(e);
    }

    for (size_t i = 1; i <= N; i++)
    {
        if (visit[i]) continue;
        dfs(i, adjList);
    }
    
    for (vector<int>::reverse_iterator it = answer.rbegin(); it != answer.rend(); ++it)
    // for (auto it = answer.rbegin(); it != answer.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    return 0;
}