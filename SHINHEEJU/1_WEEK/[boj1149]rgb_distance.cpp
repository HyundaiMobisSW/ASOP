#include <iostream>
#include <algorithm>
using namespace std;

int getResult(int a, int b, int c){
    if(a<=b && a<=c) return a;
    else if(a>=b && b<=c) return b;
    else return c;
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int n;
    int data[1001][3];
    int dp[1001][3];

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }

    dp[0][0]=0;
    dp[0][1]=0;
    dp[0][2]=0;
    for(int i=1; i<=n; i++){
        // R
        // dp[i][0] = data[i-1][0]+min(dp[i-1][1],dp[i-1][2]);
        // G
        // dp[i][1] = data[i-1][1]+min(dp[i-1][0],dp[i-1][2]);
        // B
        // dp[i][2] = data[i-1][2]+min(dp[i-1][0],dp[i-1][1]);

        for(int j=0; j<3; j++){
            dp[i][j] = data[i-1][j]+min(dp[i-1][(j+1)%3],dp[i-1][(j+2)%3]);
        }
    }

    cout << getResult(dp[n][0], dp[n][1], dp[n][2]);

    return 0;
}
