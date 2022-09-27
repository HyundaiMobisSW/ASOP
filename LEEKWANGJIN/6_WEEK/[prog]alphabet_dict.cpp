#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> v;
string alpha = "AEIOU";

int dfs(int id,string word1, string wr){
    
    if(id == wr.size()){
        v.push_back(wr);
        return 0;
    }
    
    for(int i = 0; i < 5; i++){
        dfs(id, word1, wr + word1[i]);
    }
}

int main() {
    int answer = 0;
    for(int i = 1; i < 6; i++){
        string st;
        dfs(i, alpha, st);
    }
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << "\n";
    // }
    
    sort(v.begin(), v.end());
    for(auto i : v){
        cout << i << '\n';
    }
    return answer;
}