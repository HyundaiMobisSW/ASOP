#include <iostream>
int N, M;
int arr[50], arr_re[50];
int arr_temp[50];
int arr2[99];
int res, temp;
int res_arr[100][50];
int flag = 0, flag_re = 0;

using namespace std;
// 3 2 3 3 2 1 1 1 4 4 3 2 3 3 2 1 1 1 4
int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        arr[i] = temp;
        if (temp == 1) temp = 3;
        else if (temp == 2) temp = 4;
        else if (temp == 3) temp = 1;
        else if (temp == 4) temp = 2;
        arr_re[i] = temp;
    }
    // for(int i = 0; i < N; i++){
    //     arr_temp[i] = arr_re[N-i-1];
    // }
    
    // for(int i = 0; i < N; i++){
    //     arr_re[i] = arr_temp[i];
    // }
    cin >> M;
    // for(int j = 0; j < N; j++){
    //     cout << arr_re[j] << " ";
    // }
    // cout << '\n';
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){   
            cin >> arr2[j];
        }
        for(int j = 0; j < N; j++){
            arr2[j + N] = arr2[j];
        }
        for(int j = 0; j < N; j++){
            flag = 0;
            flag_re = 0;
            for(int k = 0; k < N; k++){
                if(arr2[j+k] != arr[k]) {
                    flag = 1;
                }
            }
            for(int k = 0; k < N; k++){
                if(arr2[2*N - (1 + j+k)] != arr_re[k]) {
                    flag_re = 1;
                }
            }
            if(flag == 0 || flag_re == 0) {
                for(int k = 0; k < N; k++){
                    res_arr[res][k] = arr2[k];
                }
                res += 1;
            }
        }
    }
    cout << res << endl;
    for(int i = 0; i < res; i++){
        for(int j = 0; j < N; j++){
            cout << res_arr[i][j]<< " ";
        }
        cout << '\n';
    }
    return 0;
}