#include <iostream>

using namespace std;

int N;
int arr[1000];
int DP[1000];
int res = -1;
int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < N; i++){
        //cout << DP[i] << " ";
        DP[i] = arr[i];
    }
    //DP[0] = arr[0];
    for(int j = 0; j < N; j++){
        for(int i = j+1; i < N; i++){
            if(arr[i] > arr[j] && DP[j] + arr[i] > DP[i]){
                DP[i] = DP[j] + arr[i];
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(DP[i] > res) res = DP[i];
    }
    cout << res;

    return 0;
}