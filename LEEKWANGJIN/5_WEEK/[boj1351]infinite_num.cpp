#include <iostream>
#include <map>

using namespace std;

long long N, P, Q;
map<long long, long long> m;

long long DFS(long long N){
    if(m.count(N)) return m[N];
    return m[N]= DFS(N/P) + DFS(N/Q);
}


int main(){
    freopen("input.txt", "r", stdin);
    
    cin >> N >> P >> Q;
    m[0] = 1;
    cout << DFS(N)<< '\n';
    return 0;
}
// A0 = 1
// A1 = A1/2 + A1/3 = A0 + A0
// A2 = A2/2 + A2/3 = A0 + A0
// A3 = A3/2 + A3/3 = A1 + A0
// A4 = A4/2 + A4/3 = A1 + A1
// A5 = A5/2 + A5/3 = A2 + A1
// A6 = A6/2 + A6/3 = A2 + A1
// A7 = A7/2 + A7/3 = A3 + A2 = A1 + A0 + A0 + A0
// 256 2 4
// A0 = 1
// A1 = A1/2 + A1/4 = A0 + A0
// A2 = A2/2 + A2/4 = A0 + A0

// AN = AN/P + AN/Q