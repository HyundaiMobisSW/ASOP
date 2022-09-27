#include <iostream>
#include <stack>
using namespace std;

int n, h;
stack<int> height;
stack<int> idx;

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> h;
        while(!height.empty()){
            if(height.top()>h){
                cout << idx.top() << ' ';
                break;
            }
            height.pop();
            idx.pop();
        }
        if(height.empty()) cout << 0 << ' ';
        height.push(h);
        idx.push(i);
    }
    return 0;
}
