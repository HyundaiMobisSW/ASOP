#include <iostream>
#include <stack>

using namespace std;

int N;
int temp;
int arr[500000];
stack<pair<int, int>> st;

int main(){
    freopen("input.txt", "r", stdin);
    arr[0] = 0;
    cin >> N;
    cin >> temp;
    st.push(make_pair(temp, 0));
    //cout << st.top().first;
    for(int i = 1; i < N; i++){
        cin >> temp;
        //cout << temp << " " << st.top().first <<  "\n";
        while(!st.empty()){
            if(temp < st.top().first) break;
            //cout << st.top().first << st.top().second << '\n';
            st.pop();
        }
        if(st.empty()) arr[i] = 0;
        else arr[i] = st.top().second+1;
        st.push(make_pair(temp, i));
    }
    for(int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    return 0;
}