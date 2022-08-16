#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int N, M, y, x, cost, startt, dess;
// int arr[1001][1001] = { 0 };
// int visit[1000] = { 0 };
int dis[1001] = { 0 };

vector<pair<int, int> > arr2[1001];

#if 0 // O(N^2)
int getSmallIndex() {
    int min = 21e8;
    int idx = 0;
    for(int i = 1; i < N + 1; i++){
        if(dis[i] < min && visit[i] == 0){
            min = dis[i];
            idx = i;
        }
    }
    return idx;
}

void dijkstra(int start){
    for(int i = 1; i < N+1; i++){
            dis[i] = arr[start][i];
    }
    visit[start] = 1;
    for(int i = 1; i < N - 1; i++){
        int current = getSmallIndex();
        visit[current] = 1;
        for(int j = 1; j < N+1; j++){
            if(visit[j] == 0){
                if(dis[current] + arr[current][j] < dis[j]){
                    dis[j] = dis[current] + arr[current][j];
                }
            }
        }
    }
}
#endif

void dijkstra(int start){
    dis[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();
        if(dis[current] < distance) continue;
        for(int i = 0; i < arr2[current].size(); i++){
            int next = arr2[current][i].first;
            int nextDistance = distance + arr2[current][i].second;
            if(nextDistance < dis[next]) {
                dis[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

int main(void){
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i = 1; i < N+1; i++){
        dis[i] = 21e7;
    }

    for(int i = 0; i < M; i++){
        cin >> y >> x >> cost;
        arr2[y].push_back(make_pair(x, cost));
    }

#if 0 // O(N^3)
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            for(int k = 1; k < N+1; k++){
                arr[j][k] = arr[j][k] > arr[j][i] + arr[i][k] ? arr[j][i] + arr[i][k] : arr[j][k];
            }
        }
    }

    // for(int i = 1; i < N+1; i++){
    //     for(int j = 1; j < N+1; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    cout << arr[start][des] << '\n';

#endif
    cin >> startt >> dess;
    dijkstra(startt);

    // for(int i = 1; i < N+1; i++){
    //     cout << dis[i]<< " ";
    // }

    cout << dis[dess];
    return 0;
}