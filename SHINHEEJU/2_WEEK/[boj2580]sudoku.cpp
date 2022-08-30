#include <iostream>
using namespace std;

int board[9][9];
bool row[9][9];
bool col[9][9];
bool box[9][9];

bool isValid(int y, int x, int num){ // y=1 x=4 n=3
    // if(col[x][num-1]==true) return false;
    // if(row[y][num-1]==true) return false;
    // if(box[y/3*3 + x/3][num-1]==true) return false;

    for(int i=0; i<9; i++){
        if(board[i][x] == num) return false;
        if(board[y][i] == num) return false;
    }

    int y3 = y/3*3;
    int x3 = x/3*3;

    for(int i=y3; i<y3+3; i++){
        for(int j=x3; j<x3+3; j++){
            if(board[i][j] == num) return false;
        }
    }

  return true;
}


void solve(int y, int x){
    if(x==9){
        x=0;
        y++;
    }
    if(y==9){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        exit(0);
    }

    if(board[y][x] != 0){
        solve(y, x+1);
        return;
    }

    for(int num=1; num<=9; num++){
        if(isValid(y, x, num)){
            board[y][x] = num;

            // bool save[3];
            // save[0]=row[y][num-1];
            // save[1]=col[x][num-1];
            // save[2]=box[y/3*3 + x/3][num-1];

            // row[y][num-1]=true;
            // col[x][num-1]=true;
            // box[y/3*3 + x/3][num-1]=true;

            solve(y, x+1);

            board[y][x] = 0;
            // row[y][num-1]=save[0];
            // col[x][num-1]=save[1];
            // box[y/3*3 + x/3][num-1]=save[2];
        }
    }
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int num;
            cin >> num;
            board[i][j] = num;
            // row[i][num-1]=true;
            // col[j][num-1]=true;
            // box[i/3*3 + j/3][num-1]=true;
        }
    }

    // cout << endl;
    // for(int i=0;i<9;i++){
    //   for(int j=0;j<9;j++)
    //     cout<<row[i][j]<<" ";
    //   cout<<endl;
    // }
    //cout << endl;
    solve(0,0);
}


// row, col 체크하면서 변경