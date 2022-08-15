#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

#define INF 100000000

using namespace std;

struct node {
    int v,w;
};

int n,m;
vector<vector<node>> alist;
int start_city, end_city;

bool operator< (node a, node b){
    return b.w < a.w;
}

int dijkstra() {
    vector<int> dp(n + 1, INF);
    dp[start_city] = 0;
    priority_queue<node> q;
    q.push({start_city, 0});

    while(!q.empty()) {
        node now = q.top();
        q.pop();

        if(now.v == end_city) break;
        
        for(int i =0; i < alist[now.v].size(); i++) {
            node next = alist[now.v][i];

            if(dp[next.v] > dp[now.v] + next.w) {
                dp[next.v] = dp[now.v] + next.w;
                q.push({next.v, dp[next.v]});
            }
        }
    }

    return dp[end_city];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    alist.assign(n + 1, {});
    
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;

        alist[s].push_back({e, w});
    }

    cin >> start_city >> end_city;

    cout << dijkstra();

}
