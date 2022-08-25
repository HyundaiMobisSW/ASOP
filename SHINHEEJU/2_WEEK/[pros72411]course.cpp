#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> info;
int cnt[11]; 
string str;

void combination(int idx, string order){
    for(int i=idx; i<order.size(); i++){
            str += order[i];
            if(info.find(str) == info.end()){
                info.insert(pair<string,int>(str,1));
            }
            else info[str]++;
            if(cnt[str.size()] < info[str]){
                cnt[str.size()] = info[str];
            }
            combination(i+1, order);
            str.pop_back();
    }   
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(int i=0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
        combination(0, orders[i]);
    }
    
    for(int i=0; i<course.size(); i++){    
        for(auto iter=info.begin(); iter!=info.end(); iter++){
            int len = iter->first.length();
            if(iter->second < 2) continue;
            if(len == course[i] && iter->second == cnt[len]){
                answer.push_back(iter->first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}