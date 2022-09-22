#include <iostream>
#include <vector>
#include <queue>

#define MAX 32001
using namespace std;
int N,M,A,B;
// 1. indegree == 0 인 것을 탐색.
// 2. 관련 엣지를 제거하고 indegree를 업데이트.
// 3. 1, 2 반복하고 루프 종료후, 모든 노드 탐색했는지 확인.

int indegree[MAX];
vector<int> v[MAX];
queue<int> q;

void topologySort() {
    int result[MAX];
    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0) q.push(i);
    }
    for(int i = 1; i <= N; i++){
        int x = q.front();
        q.pop();
        result[i] = x;
        for(int i 2= 0; i < v[x].size();i++){
            int y = v[x][i];
            if(--indegree[y] == 0) q.push(y);
        }
    }
    for(int i = 1; i <= N; i++){
        cout << result[i] << " ";
    }
    cout << '\n';
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> A >> B;
        v[A].push_back(B);
        indegree[B]++;
    }
    topologySort();
    return 0;
}
