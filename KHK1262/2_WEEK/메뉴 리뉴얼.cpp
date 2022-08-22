#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
using P = pair<int, string>;

void make_comb(string& word, string temp, int depth, int index, vector<string>& data) {
    if (depth == temp.size()) {
        sort(temp.begin(), temp.end());
        data.push_back(temp);
    }
    else if (index == word.size()) return;
    else {
        temp.push_back(word[index]);
        make_comb(word, temp, depth, index + 1, data);
        temp.pop_back();
        make_comb(word, temp, depth, index + 1, data);
    }
}

void find_freq(priority_queue<P>& temp, vector<string> data) {
    int curF = 0;
    for (int i = 0; i < data.size(); i++) {
        ++curF;
        if(i == data.size()-1)
            temp.push({ curF, data[i] });

        else if (data[i] != data[i + 1]) {
            temp.push({ curF, data[i] });
            curF = 0;
        }
    }

}


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < course.size(); i++) {
        vector<string> temp_list;

        for (int j = 0; j < orders.size(); j++) {
            vector<string> temp;
            make_comb(orders[j], "", course[i], 0, temp);
            temp_list.insert(temp_list.end(), temp.begin(), temp.end());
        }

        if (temp_list.size()) {
            sort(temp_list.begin(), temp_list.end());
            priority_queue<P> c;
            find_freq(c, temp_list);

            int most = c.top().first;
            for (int i = 0; i < c.size(); i++) {
                if (1 < most && most == c.top().first) {
                    answer.push_back(c.top().second);
                    c.pop();
                }
                else
                    break;
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}