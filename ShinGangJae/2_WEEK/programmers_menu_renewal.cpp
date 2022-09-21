#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

pair<vector<string>, int> totAnswers[11];
map<string, int> courses;
bool visit[10] = { false, };

void getCourses(int start, string order, string curCourse){
    if(start == order.length()) return;
    if(courses.find(curCourse) == courses.end()) courses[curCourse] = 1;
    else courses[curCourse]++;
    for(int i = start; i < order.length(); i++){
        if(visit[i]) continue;
        visit[i] = true;
        getCourses(i, order, curCourse + order[i]);
        visit[i] = false;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i = 0; i < orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
        getCourses(0, orders[i], "");
    }
    for(const auto &[key, value] : courses){
        if((key.length() > 1)&&(value > 1)){
            if(value > totAnswers[key.length()].second){
                totAnswers[key.length()].first.clear();
                totAnswers[key.length()].first.push_back(key);
                totAnswers[key.length()].second = value;
            }
            else if(value == totAnswers[key.length()].second){
                totAnswers[key.length()].first.push_back(key);
            }
        }
    }
    for(auto count : course) {
        for(auto ans : totAnswers[count].first) answer.push_back(ans);
    }
    sort(answer.begin(), answer.end());
    return answer;
}