#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int V;
int visit[100001];
int Maxdis, Maxnode;
vector<pair<int, int>> v[100001];

int dfs(int x, int dis){
    if(visit[x]) return 0;
    visit[x] = 1;
    if(dis > Maxdis) {
        Maxdis = dis;
        Maxnode = x;
    }
    for (int i = 0; i < v[x].size(); i++) {
        int ni = v[x][i].first;
        int nd = v[x][i].second;
        dfs(ni, nd + dis);
        visit[x] = 0;
    }
    return 0;
}
int main(){
    freopen("input.txt", "r", stdin);
    cin >> V;
    for(int i = 0; i < V; i++){
        int N;
        int x, y;
        cin >> N;
        cin >> x;
        while(x != -1){
            cin >> y;
            v[N].push_back({x, y});
            cin >> x;
        }
    }

    dfs(1, 0);
    memset(visit, 0, sizeof(visit));
    Maxdis = 0;
    dfs(Maxnode, 0);

    cout << Maxdis;
    return 0;
}