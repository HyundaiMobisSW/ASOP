#include <iostream>
using namespace std;

int n, m;
int board[51][51];
int dp[51][51];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int visit[51][51];
int check[51][51];

int dfs(int x, int y){
    //cout << x << " " << y << " " << board[x][y] << endl;
    if(board[x][y]==0) return 0;
    //보드 밖으로 벗어난 경우
    if( x<1 || x>n || y<1 || y>m ) return 0;
    // 동전을 무한히 움직이는 경우
    if(check[x][y]==1){
        cout << -1;
        exit(0);
    }
    //dp 값이 정해진 경우
    if(visit[x][y]==1){
        return dp[x][y];
    }
    check[x][y]=1;
    visit[x][y]=1;
    for(int i=0; i<4; i++){
        int new_x, new_y;
        new_y = y + (board[x][y] * dir[i][0]);
        new_x = x + (board[x][y] * dir[i][1]);

        // if( x>=1 && x<=n && y>=1 && y<=m && dp[new_x][new_y]!=0){
        //     cout << -1;
        //     exit(0);
        // }
        dp[x][y] = max(dp[x][y], dfs(new_x, new_y)+1);
    }
    check[x][y]=0;
    return dp[x][y];
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    // 입력
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string str;
        cin >> str;
        for(int j=1; j<=m; j++){

            if(str[j-1]=='H'){
                board[i][j]= 0;
            } else{
                board[i][j]= str[j-1]-'0';
            }
        }
    }

    cout << dfs(1,1);
}
