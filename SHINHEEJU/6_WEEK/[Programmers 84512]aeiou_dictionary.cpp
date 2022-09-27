#include <string>

using namespace std;

string key[5] = {"A","E","I","O","U"};
int depth = -1;
int result;
int isEnd;

void dfs(string target, string answer){
    if(target.size()>5){
        return;
    }
    else{
        depth++;
    }
    if(target==answer){
        result = depth;
        isEnd = 1;
    }
    
    for(int i=0; i<5; i++){
        target += key[i];
        if(isEnd==1) break;
        dfs(target, answer);
        target.pop_back();
    }
    return;
}

int solution(string word) {
    dfs("", word);
    return result;
}

////////////////////////////

#include <string>

using namespace std;

int solution(string word) {
    int weights[5]={781,156,31,6,1};
    string key = "AEIOU";
    int answer = 0;
    for(int i=0; i<word.size(); i++){
        answer += 1 + (key.find(word[i])) * weights[i];
    }
    return answer;
}

// 1   =                         5^0     = 1
// 6   =                   5^1 + 5^0     = 5 + 1
// 31  =             5^2 + 5^1 + 5^0     = 25 + 5 + 1
// 156 =       5^3 + 5^2 + 5^1 + 5^0     = 125 + 25 + 5 + 1
// 781 = 5^4 + 5^3 + 5^2 + 5^1 + 5^0     = 625 + 125 + 25 + 5 + 1