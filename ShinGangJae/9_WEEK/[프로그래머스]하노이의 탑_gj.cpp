#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void getAnswer(int n, int from, int mid, int to){
    if(!n) return;
    getAnswer(n - 1, from, to, mid);
    answer.push_back({from, to});
    getAnswer(n - 1, mid, from, to);
}

vector<vector<int>> solution(int n) {
    getAnswer(n, 1, 2, 3);
    
    return answer;
}