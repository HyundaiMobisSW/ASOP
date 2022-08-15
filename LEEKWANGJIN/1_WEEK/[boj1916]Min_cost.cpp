#include <iostream>

using namespace std;

int N, M, y, x, cost, start, des;
int arr[1001][1001] = { 0 };

int main(void){
    freopen("input.txt", "r", stdin);

    cin >> N >> M;

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++) {
            if (i == j) continue;
            arr[i][j] = 21e7;
        }
    }

    for(int i = 0; i < M; i++){
        cin >> y >> x >> cost;
        if(arr[y][x] > cost) arr[y][x] = cost;
    }

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            for(int k = 1; k < N+1; k++){
                arr[j][k] = arr[j][k] > arr[j][i] + arr[i][k] ? arr[j][i] + arr[i][k] : arr[j][k];
            }
        }
    }

    // for(int i = 1; i < N+1; i++){
    //     for(int j = 1; j < N+1; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    
    cin >> start >> des;
    cout << arr[start][des] << '\n';
    return 0;
}