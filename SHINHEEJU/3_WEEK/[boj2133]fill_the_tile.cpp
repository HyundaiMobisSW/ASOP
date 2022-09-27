#include <iostream>
using namespace std;

int N;
int info[32];

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> N;  

    if (N%2 == 1){
        cout << 0;
    }
    else{
        info[0]=1;
        info[1]=0;
        info[2]=3;
        for(int i=4; i<=N; i+=2){
            info[i]=info[i-2]*3;
            for(int j=0; j<=i-4; j+=2){
                info[i] += info[j]*2;
            }
        }
    cout << info[N];
    }
}
