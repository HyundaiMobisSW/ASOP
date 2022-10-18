#include <iostream>
#include <vector>

using namespace std;
int parents[51];
int N, M, P, temp, answer, num, num_pre;

vector<int> know_p;
vector<vector<int>> Party(51);


int fp(int x){
    if(parents[x] == x) return x;
    return x = fp(parents[x]);
}

void Union(int x, int y){
    x = fp(x);
    y = fp(y);
    parents[x] = y;
}

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        parents[i] = i;
    }

    cin >> P;
    for(int i = 0; i < P; i++){
        cin >> temp;
        know_p.push_back(temp);
    }

    for(int i = 0; i < M; i++){
        cin >> temp;
        for(int j = 0; j < temp; j++){
                if( j >= 1){
                    num_pre = num;
                    cin >> num;
                    Union(num_pre, num);
                }
                else cin >> num;
                Party[i].push_back(num);
        }
    }
    for(int i = 0; i < Party.size(); i++){
        int flag = 0;
        for(int j = 0; j < Party[i].size(); j++){
            for(int k = 0; k < know_p.size(); k++){
                //cout << k << " ";
                if(fp(Party[i][j]) == fp(know_p[k])){
                    flag = 1;
                    //cout << Party[i][j] << " " << know_p[k] << " ";
                    break;
                }
            }
            //cout << endl;
        }

        M -= flag;
    }

    cout << M;
    return 0;
}