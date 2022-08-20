#include <iostream>
#include <vector>
#include <queue>
using namespace std;

    int N, M;
    int INF = 2100000000;
    int start, dest;
    int min_dist[1001];
    bool visited[1001];
    vector<pair<int, int> > graph[100001];
    priority_queue<pair<int, int> > sequence;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> N >> M;
    for(int i=1; i<=N; i++) min_dist[i] = INF;
    for(int i=1; i<=N; i++) visited[i] = false;

    while(M--){
        int s, e, d;
        cin >> s >> e >> d;
        graph[s].push_back(make_pair(e,d));
    }
    cin >> start >> dest;

    min_dist[start]=0;
    sequence.push(make_pair(0,start));

    while(!sequence.empty()){
        int dist = -sequence.top().first;
        int city = sequence.top().second;
        sequence.pop();

        if(visited[city]) continue;
        visited[city] = true;

        if(min_dist[city] < dist) continue;

        for(int i=0; i<graph[city].size(); i++){
            int city_next=graph[city][i].first;
            int dist_next=dist+graph[city][i].second;
            if(min_dist[city_next] > dist_next){
                min_dist[city_next]= dist_next;
                sequence.push(make_pair(-dist_next, city_next));
            }
        }
    }

    cout << min_dist[dest];
    return 0;
}