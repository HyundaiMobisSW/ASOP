#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> dict;
string base = "AEIOU";
int index = 1;
void make(int ind, string word)
{
    if (ind == 6)
    {
        return;
    }
    if (word != "" && !dict.count(word)) 
    {
        dict[word] = index;
        index++;
    }
    for (int i=0; i<5; i++)
    {
        make(ind+1, word+base[i]);
    }

    return ;
}

int solution(string word) {
    make(0, "");
    
    return dict[word];
}