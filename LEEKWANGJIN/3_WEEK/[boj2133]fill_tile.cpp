#include <iostream>

using namespace std;
int res[31];
int N;
int SUM;
int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    res[0] = 1;
    res[2] = 3;
    res[4] = 11;
    for(int i = 6; i < 32; i=i+2){
        SUM = 0;
        for(int j = i-4; j >= 0; j = j - 2){
            SUM += res[j];
        }
        res[i] = res[i-2]*3 + SUM*2;
    }
    cout << res[N] << " ";
    return 0;
}