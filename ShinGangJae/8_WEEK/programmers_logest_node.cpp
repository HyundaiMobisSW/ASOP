#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int max(int a, int b, int c){
    a = a > b ? a : b;
    return a > c ? a : c;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max_vertex = 0, tmp = 0;
    bool visit[20001] = {false, };
    vector<int> graph[20001];
    queue<int> q;
    for(int i = 0; i < edge.size(); i++){
        int v1 = edge[i][0], v2 = edge[i][1];
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
        max_vertex = max(max_vertex, v1, v2);
    }
    q.push(1);
    visit[1] = true;
    while(!q.empty()){
        int size = q.size();
        answer = size;
        while(size--){
            int vertex = q.front();
            q.pop();
            for(int i = 0; i < graph[vertex].size(); i++){
                int nv = graph[vertex][i];
                if(!visit[nv]){
                    q.push(nv);
                    visit[nv] = true;
                }
            }
        }
    }
    return answer;
}