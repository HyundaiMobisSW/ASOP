#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int info[101][2]; // W V
int maxV[101][100001];

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> info[i][0] >> info[i][1];
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){ 
            if(info[i][0]>j){
                maxV[i][j]=maxV[i-1][j];
            }
            else{
                maxV[i][j]=max(maxV[i-1][j], maxV[i-1][j-info[i][0]]+info[i][1]);
            }
        }
    }
    cout << maxV[N][K];
}
