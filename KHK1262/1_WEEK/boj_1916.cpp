#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

using P = pair<int, int>;

const int MAX_DIS = 1000000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;

    cin >> n;
    cin >> m;

    vector<vector<P>> graph(n);
    vector<int> dist(n, MAX_DIS);    

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u-1].push_back({v-1, w});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    
    int s, e;
    cin >> s >> e;

    dist[s-1] = 0;
    pq.push({0,s-1});

    while(!pq.empty()){
        int distance = pq.top().first;
        int cur_node = pq.top().second;
    
        pq.pop();

        if(dist[cur_node] < distance)
            continue;

        for(auto v : graph[cur_node]){
            int next_distance = v.second + distance;
            int next_node = v.first;
            if(next_distance < dist[next_node]){
                dist[next_node] = next_distance;
                pq.push({next_distance, next_node});
            }
        }
    }
    cout << dist[e-1] << endl;
}