#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer, cnt;

char alphaTable[5] = {'A', 'E', 'I', 'O', 'U'};

void getAnswer(string word, string curWord){
    if(curWord.length() > 5) {cnt--; return;}
    if(word == curWord){
        answer = cnt;
        return;
    }
    for(int i = 0; i < 5; i++){
        cnt++;
        getAnswer(word, curWord + alphaTable[i]);
    }
}

int solution(string word) {
    getAnswer(word, "");
    return answer;
}