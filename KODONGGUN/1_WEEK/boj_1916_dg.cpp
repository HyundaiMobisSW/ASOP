#include <iostream>
#include <vector>
#include <array>
#include <queue>
using namespace std;

int main()
{
  // 1 Initialize
  int N, M, start, end, answer;
  // vector<array<int, 3>> bus;
  cin >> N;
  cin >> M;
  // 1-1 make graph with bus informations, Uni-direct
  vector<vector<pair<int, int>>> linked_list;
  for (int i = 0; i < N + 1; i++)
  {
    linked_list.push_back(vector<pair<int, int>>());
  }

  for (int i = 0; i < M; i++)
  {
    int s, e, cost;
    vector<pair<int, int>> tmp_vector;
    cin >> s >> e >> cost;
    linked_list[s].push_back(make_pair(e, cost));
  }

  cin >> start >> end;

  // 1-2 create visit array, and initialize 0
  int *visit = new int[N + 1]();

  // 2 Algorithm - Dijkstra
  answer = 0;
  priority_queue<pair<int, int>> pq; // desc
  pq.push(make_pair(0, start));
  // cout << "--" << endl;
  while (!pq.empty())
  {
    int cur, cur_cost;
    cur_cost = -pq.top().first;
    cur = pq.top().second;
    // cout << cur_cost << " " << cur << endl;
    pq.pop();
    if (cur == end)
    {
      answer = cur_cost;
      break;
    }
    if (visit[cur])
    {
      continue;
    }
    visit[cur] = 1;

    for (auto adj : linked_list[cur])
    {
      int adj_node, adj_cost;
      adj_node = adj.first;
      adj_cost = adj.second;
      if (visit[adj_node])
        continue;
      pq.push(make_pair(-(cur_cost + adj_cost), adj_node));
    }
  }

  // 3 Print answer
  cout << answer << endl;

  // 4
  delete[] visit;
  return 0;
}
