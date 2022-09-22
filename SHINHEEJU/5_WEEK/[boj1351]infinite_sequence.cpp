#include <iostream>
#include <map>
using namespace std;

long long n;
int p, q;
map<long long, long long> info;

long long solve(long long n){
    // if(info.find(n) == info.end()){
    //     info.insert(make_pair(n, solve(n/p)+solve(n/q)));
    // }
    // return info.find(n)->second;
    if(info.find(n) == info.end()){
        info[n]=solve(n/p)+solve(n/q);
    }
    return info[n];
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    cin >> n >> p >> q;

    info.insert(make_pair(0,1));
    cout << solve(n); 
    return 0;
}

// division by zero ( int n 선언 )