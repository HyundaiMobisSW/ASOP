#include <iostream>

using namespace std;

int N;
int arr[1000][3];
int res = 21e8;

int main(void){
    freopen("input.txt", "r", stdin);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0){
                arr[i][j] = arr[i][j] + ((arr[i-1][1] > arr[i-1][2]) ? arr[i-1][2] : arr[i-1][1]);
            }
            else if(j == 1){
                arr[i][j] = arr[i][j] + ((arr[i-1][0] > arr[i-1][2]) ? arr[i-1][2] : arr[i-1][0]);
            }
            else {
                arr[i][j] = arr[i][j] + ((arr[i-1][0] > arr[i-1][1]) ? arr[i-1][1] : arr[i-1][0]);
            }
        }
    }
    for(int i = 0; i < 3; i++){
        res = (res > arr[N-1][i]) ? arr[N-1][i] : res;
    }
    
    cout << res <<endl;
    return 0;
}