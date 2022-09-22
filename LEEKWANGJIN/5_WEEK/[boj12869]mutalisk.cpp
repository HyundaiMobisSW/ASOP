#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[3];
int cnt;
int Min = 21e8;
int visit[61][61][61];

bool desc(int x, int y){
    return x > y;
}

int DFS(int x, int y, int z, int cnt){
    if(cnt > Min) return 0;
    
    x = max(0, x);
    y = max(0, y);
    z = max(0, z);

    arr[0] = x;
    arr[1] = y;
    arr[2] = z;

    sort(arr, arr+3, desc);

    x = arr[0];
    y = arr[1];
    z = arr[2];

    // cout << x << " " << y << " " << z << '\n';
    
    
    if(x < 1 && y < 1 && z < 1){
        if(Min > cnt) Min = cnt;
        return 0;
    }

    if(visit[x][y][z] == 1) return 0;
    
    visit[x][y][z] = 1;
    
    DFS(x - 9, y - 3, z - 1, cnt+1);
    DFS(x - 9, y - 1, z - 3, cnt+1);
    DFS(x - 3, y - 9, z - 1, cnt+1);
    DFS(x - 3, y - 1, z - 9, cnt+1);
    DFS(x - 1, y - 9, z - 3, cnt+1);
    DFS(x - 1, y - 3, z - 9, cnt+1);

    return 0;
}


int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    if(N==1) cin >> arr[0];
    if(N==2) cin >> arr[0] >> arr[1];
    if(N==3) cin >> arr[0] >> arr[1] >> arr[2];
    DFS(arr[0], arr[1], arr[2], 0);
    cout << Min << '\n';
    return 0;
}