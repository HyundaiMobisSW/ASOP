#include <iostream>
using namespace std;

int s, num, result = 0;
int info[51];
int infoR[51];
int comp[101][51];
bool isSame[101];

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    cin >> s;
    for(int i=0; i<s; i++){
        cin >> info[i];
        if(info[i]!=2)
            infoR[i]=(info[i]+2)%4;
        else
            infoR[i]=4;
    }

    cin >> num;
    for(int i=0; i<num; i++){
        for(int j=0; j<s; j++){
            cin >> comp[i][j];
        }
    }

    for(int i=0; i<num; i++){ //모양
        for(int j=0; j<s; j++){
            //순차
            if(comp[i][j] == info[0]){
                int k;
                for(k=0; k<s; k++){
                    if(comp[i][(j+k)%s] != info[k]){
                        break;
                    }
                }
                if(k==s){
                    isSame[i]=true;
                    result++;
                }
            }
            //역순
            if (comp[i][j] == infoR[0]){
                int k;
                for(k=0; k<s; k++){
                    if(comp[i][(j-k+s)%s] != infoR[k]){
                        break;
                    }
                }
                if(k==s){
                    isSame[i]=true;
                    result++;
                }
            }
        }
    }

    cout << result << endl;
    for(int i=0; i<num; i++){
        if(isSame[i]){
            for(int j=0; j<s; j++){
                cout << comp[i][j] << ' ';
            }
            cout << endl;
        }
    }

}
