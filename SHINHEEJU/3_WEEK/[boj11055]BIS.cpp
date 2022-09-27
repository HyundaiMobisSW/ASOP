#include <iostream>
#include <algorithm>
using namespace std;

int N;
int info[1002];
int sum[1002];
int result;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> N;
    info[0]=0;
    sum[0]=0;
    for(int i=1; i<=N; i++){
        cin >> info[i];
    }

    for(int i=1; i<=N; i++){
        //cout << "info is " << info[i] << endl;
        int maxSum = 0;
        for(int j=i-1; j>=0; j--){
            //cout << "compare num is " << info[j] << endl;
            if(info[j]<info[i]){
                maxSum = max(maxSum, sum[j]);
            }
        }
        sum[i]=maxSum+info[i];
        //cout << "-> " << sum[i] << endl;
        result = max(result, sum[i]);
    }
    cout << result;
}
