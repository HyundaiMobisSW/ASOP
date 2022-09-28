#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;


int solution(string word) {
    int answer = word.size();
    int arr1[5] = { 781, 156, 31, 6, 1 };
    map<char, int> s;

    s['A'] = 0;
    s['E'] = 1;
    s['I'] = 2;
    s['O'] = 3;
    s['U'] = 4;

    for (int i = 0; i < word.size(); i++)
        answer += s[word[i]] * arr1[i];

    return answer;
}


int main() {

    cout << solution("AAAE");
}