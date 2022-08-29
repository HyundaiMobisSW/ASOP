#include <iostream>
#include <vector>


using namespace std;
#define SIZE    9
int MAP[SIZE][SIZE];
vector<pair<int, int>> v;
int valid_num[10];


int valid_check(int &y, int &x){
    int flag = 0;
    int sum = 0;
    for(int j = 0; j < 10; j++) valid_num[j] = 0;
    // cout << y << " " << x << endl;
    // for(int xx = 0; xx < 10; xx++){
    //     cout <<  valid_num[xx] << " ";
    // }
    // cout << '\n';
    // for(int y = 0; y < SIZE; y++){
    //     for(int x = 0; x < SIZE; x++){
    //         cout <<  MAP[y][x] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << endl;
    for(int yy = 0; yy < 9; yy++){
        valid_num[MAP[(y+yy)%9][x]] = 1;
    }
    for(int xx = 0; xx < 9; xx++){
        valid_num[MAP[y][((x+xx)%9)]] = 1;
    }
    for(int yy = 0; yy < 3; yy++){
        for(int xx = 0; xx < 3; xx++){
            valid_num[MAP[y / 3 * 3 + yy][x / 3 * 3 + xx]] = 1;
        }
    }
    for(int i = 1 ; i < 10; i++){
        sum += valid_num[i];
    }
    // for(int xx = 0; xx < 10; xx++){
    //     cout <<  valid_num[xx] << " ";
    // }
    // cout << '\n';
    if(sum != 9) return 1;
    
    return 0;
}


void dfs(int idx){
        if(idx > v.size()) return;
        int y = v[idx].first;
        int x = v[idx].second;

        if(valid_check(y, x)){
            // cout << "true" << endl;;
            //vector<int> vv;
            for(int k = 1; k < 10; k++){
                if(valid_num[k] == 0) {
                MAP[y][x] = k;
                dfs(idx+1);
                MAP[y][x] = 0;
                }
            }
            // for(int k = 0; k < vv.size(); k++){

            // }
        }
        else {
            return;
        }
        
    return;
}




int main(){
    freopen("input.txt", "r", stdin);

    for(int y = 0; y < SIZE; y++){
        for(int x = 0; x < SIZE; x++){
            cin >> MAP[y][x];
            if(MAP[y][x] == 0) v.push_back(make_pair(y, x));
        }
    }
    dfs(0);
    for(int y = 0; y < SIZE; y++){
        for(int x = 0; x < SIZE; x++){
            cout <<  MAP[y][x] << " ";
        }
        cout << '\n';
    }
    //cout << '\n';
    return 0;
}












#include <iostream>
using namespace std;

int board[9][9];
bool row[9][9];
bool col[9][9];
bool box[9][9];

bool isValid(int y, int x, int num){ // y=1 x=4 n=3
    // if(col[x][num-1]==true) return false;
    // if(row[y][num-1]==true) return false;
    // if(box[y/33 + x/3][num-1]==true) return false;

    for(int i=0; i<9; i++){
        if(board[i][x] == num) return false;
        if(board[y][i] == num) return false;
    }

    int y3 = y/33;
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
            // save[2]=box[y/33 + x/3][num-1];

            // row[y][num-1]=true;
            // col[x][num-1]=true;
            // box[y/33 + x/3][num-1]=true;

            solve(y, x+1);

            board[y][x] = 0;
            // row[y][num-1]=save[0];
            // col[x][num-1]=save[1];
            // box[y/33 + x/3][num-1]=save[2];
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
            // box[i/33 + j/3][num-1]=true;
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