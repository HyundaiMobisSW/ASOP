#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][3] = { 0, };
int rgb[3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
    
        cin >> rgb[0] >> rgb[1] >> rgb[2];

        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgb[0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgb[1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgb[2];
    }
        
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << endl;

}