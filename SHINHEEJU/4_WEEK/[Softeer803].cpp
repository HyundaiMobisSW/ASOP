#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int maxNum = 2000000000;
int n;
int curTime = 0;
int answer[200002];
bool chkTurn[4];
queue<pair<int, int> > q[4];

int getSmall(int a, int b, int c, int d){
    if(a<=b && a<=c && a<=d) return a;
    else if (b<=a && b<=c && b<=d) return b;
    else if (c<=a && c<=b && c<=d) return c;
    else return d;
}

int getCount(int num, int t[4]){
    int cnt=0;
    for(int i=0; i<4; i++){
        if(t[i]==num){
            cnt++;
        }
    }
    return cnt;
}

int getOne(int num, int t[4]){
    for(int i=0; i<4; i++){
        if(t[i]==num){
            return i;
        }
    }
    return -1;
}

int getNotOne(int num, int t[4]){
    for(int i=0; i<4; i++){
        if(t[i]!=num){
            return i;
        }
    }
    return -1;
}

int getTwo(int num, int t[4]){
    if(t[0]==t[1]) return 0;
    else if(t[1]==t[2]) return 1;
    else if(t[2]==t[3]) return 2;
    else return 3;
}

//int[] getTow(int num, int t[4]){

//}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    // 출력 빠르게 하는 것 추가!

    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        char dir;
        cin >> num >> dir;
        q[dir-'A'].push(make_pair(num, i));
    } // 입력

    while(1){
        //break;
        int t[4], idx[4];
        if(q[0].empty() && q[1].empty() && q[2].empty() && q[3].empty()) break;

        if(!q[0].empty()){
            t[0] = q[0].front().first;
            idx[0] = q[0].front().second;
        } else{ t[0]= maxNum+1; }
        if(!q[1].empty()){
            t[1] = q[1].front().first;
            idx[1] = q[1].front().second;
        } else{ t[1]= maxNum+2; }
        if(!q[2].empty()){
            t[2] = q[2].front().first;
            idx[2] = q[2].front().second;
        }else{ t[2]= maxNum+3; }
        if(!q[3].empty()){
            t[3] = q[3].front().first;
            idx[3] = q[3].front().second;
        } else{ t[3]= maxNum+4; }
        // 시간 우선순위 구하기 -> 가장 작은 시간 or 현재 시간이 현재 타임
        for(int i=0; i<4; i++){
            t[i] = max(t[i], curTime);
        }
        int minTime = getSmall(t[0],t[1],t[2],t[3]);
        int same = getCount(minTime, t);
        curTime = max(curTime, minTime);
        cout << curTime << "->" << t[0] << " " << t[1]  << " " << t[2]  << " " << t[3]  << " " << endl;
        cout << same << endl;
        // 4개가 시간 동일 -> -1
        if(same == 4){
            //cout << "-> 4" << endl;
            answer[idx[0]]=-1;
            break;
        }
        // 3개가 시간 동일 -> 시간 다른 것 왼쪽부터
        else if(same == 3){
            //cout << "-> 3" << endl;
            int target = (getNotOne(minTime,t)+1)%4;
            q[target].pop();
            answer[target] = curTime;
        }
        // 2개가 시간 동일
        else if(same ==2){
            cout << "-> 2 " << endl;
            // 마주보는 2개 -> 동시에 출발
            if(t[0]==t[2] || t[1]==t[3]){
                int target = (getOne(minTime, t));
                //cout << "TARGET : " << target << endl;
                q[target].pop();
                q[target+2].pop();
                answer[idx[target]] = curTime;
                answer[idx[target+2]] = curTime;
            }
            // 인접한 2개 -> 더 왼쪽에 있는 것부터 출발
            else{
                int target = getTwo(minTime, t);  
                //cout << "TARGET : " << target << endl;
                q[target].pop();
                //q[(target+1)%4].pop();
                answer[idx[target]] = curTime;
                //answer[idx[(target+1)%4]] = curTime;    
            }
        }
        // 인접한 2개 -> 더 왼쪽에 있는 것부터 출발
        // 1개가 시간 동일 -> 걔부터 출발
        else if(same == 1){
            int target = (getOne(minTime, t));
            //cout << "-> 1 " << target << endl;
            q[target].pop();
            answer[idx[target]] = curTime;
        }
        curTime++;
    }

    bool check = true;
    for(int i=0; i<n; i++){
        if(check)
            cout << answer[i] << endl;
        else
            cout << -1 << endl;
        if(answer[i]==-1) check = false;
    }
}

