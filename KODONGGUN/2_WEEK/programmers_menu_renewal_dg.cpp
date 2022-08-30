#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void printVector(vector<string> v);
void printVector(vector<int> v);
vector<string> splitStringWithTab(string s);
vector<string> parsingVectorString(string s);
vector<int> parsingVectorInteger(string s) ;

/* -------------- programmers start -------------- */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> // sort, max
using namespace std;

vector<int> visit(21), max_count(21);
unordered_map<string, int> m; // m[combi] = count

void insertItem(string order, int limit)
{
    vector<char> tmp_v;
    string tmp;
    for (int i=0; i<limit; i++)
    {
        if (visit[i]) 
            tmp_v.push_back(order[i]);
    }
    sort(tmp_v.begin(), tmp_v.end());
    for (auto ch: tmp_v)
        tmp += ch;
    // insert item in map
    if (m[tmp]) m[tmp]++;
    else        m[tmp] = 1;
    
    // renew max
    max_count[tmp.size()] = max(max_count[tmp.size()], m[tmp]);
}
void make_combination(string order, int start_index, int limit)
{
    // cout << start_index << " " <<limit <<endl;
    if (start_index == limit) return;
    for (int i = start_index; i < limit; i++)
    {
        if (visit[i]) continue;
        visit[i] = 1;
        insertItem(order,limit);
        make_combination(order, i + 1, limit);
        visit[i] = 0;
    }
}
bool numberInCourse(int size, vector<int>& course)
{
    for (auto crs: course)
    {
        if (crs == size) return true;
    }
    return false;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    // 1 init
    vector<string> answer;
    
    // 2 algorithm for combination
    for (auto order: orders)
    {
        make_combination(order, 0, order.size());
    }
    
    // 3 result
    for (auto mm: m)
    {   
        if (!numberInCourse(mm.first.size(), course)) continue;
        if (mm.second < 2) continue;    // if count 1, continue
        if (mm.second == max_count[mm.first.size()])
            answer.push_back(mm.first);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}

/* -------------- programmers end -------------- */

int main()
{
    ifstream fin;
    fin.open("./KODONGGUN/2_WEEK/programmers_menu_renewal_input.txt");
    if (!fin.is_open()) 
    {
        cout << "error" << endl;
        return EXIT_FAILURE;
    }

    vector<string> answer, result, orders, lineVector;
    vector<int> course;
    string line;
    string tmp;
    while(true)   
    {
        getline(fin, line);
        if (line == "") break;
        lineVector = splitStringWithTab(line);
        orders = parsingVectorString(lineVector[0]);
        course = parsingVectorInteger(lineVector[1]);
        answer = parsingVectorString(lineVector[2]);
        result = solution(orders, course);
        cout << "result == answer: " << (result == answer?"true":"false") << endl;
    }
    
    fin.close();
    return 0;
}

void printVector(vector<string> v)
{
    for (auto item: v)
    {
        cout << item << " ";
    }
    cout << endl;
}
void printVector(vector<int> v)
{
    for (auto item: v)
    {
        cout << item << " ";
    }
    cout << endl;
}

vector<string> splitStringWithTab(string s)
{
    //["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]	[2,3,4]	["AC", "ACDE", "BCFG", "CDE"]
    vector<string> ret_vector;
    string tmp = "";
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] == '\t' || s[i]== '\0')
        {
            // cout << tmp << endl;
            ret_vector.push_back(tmp);
            tmp = "";
        }
        else 
        {
            tmp += s[i];
        }
    }
    ret_vector.push_back(tmp);
    return ret_vector;
}
vector<string> parsingVectorString(string s)
{
    //["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
    vector<string> ret_vector;
    string item = "";
    bool setItem = false;
    for (size_t i = 1; i < s.size()-1; i++)
    {
        if (setItem)
        {
            if (s[i] == '\"')
            {
                setItem = false;
                ret_vector.push_back(item);
                item = "";
            }
            else
            {
                item += s[i];
            }
        }
        else 
        {
            if (s[i] == '\"')
            {
                setItem = true;
            }
            else
            {
                continue;
            }
        }
    }
    return ret_vector;
}
vector<int> parsingVectorInteger(string s) 
{
    //[2,3,4]
    vector<int> ret_vector;
    string item = "";
    for (size_t i = 1; i < s.size()-1; i++)
    {
        if (s[i] == ',')
        {
            ret_vector.push_back(stoi(item));
            item = "";
        }
        else 
        {
            item += s[i];
        }
    }
    ret_vector.push_back(stoi(item));

    return ret_vector;
}
