#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;

int N, M;
int cnt[32002];
vector<int> shorter[32002];
queue<int> q;
 
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        cnt[b]++;
        shorter[a].push_back(b);
    }

    for(int i=1; i<=N; i++){
        if(cnt[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int target = q.front();
        q.pop();
        cout << target << ' ';
        for(int i=0; i< shorter[target].size(); i++){
            int s = shorter[target][i];
            cnt[s]--;
            if(cnt[s]==0){
                q.push(s);
            }
        }
    }
    return 0;
}
