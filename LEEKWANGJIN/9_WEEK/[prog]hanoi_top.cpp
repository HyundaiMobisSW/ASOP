#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void move(int N, int start, int to){
    answer.push_back({start, to});
}

void hanoi(int N, int start, int to, int via){
    if(N == 1) move(1, start, to);
    else {
        hanoi(N-1, start, via, to);
        move(N, start, to);
        hanoi(N-1, via, to, start);
    }
    
}


vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3, 2);    
    
    return answer;
}