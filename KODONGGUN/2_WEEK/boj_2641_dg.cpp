#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check_subvector(int length, vector<int> key, vector<int> rev_key, vector<int> sub_v)
{
    for (int i = 0; i + length < key.size(); i++)
    {
        if (vector<int>(key.begin()+i, key.begin()+i+length) == sub_v)
            return true;
        if (vector<int>(rev_key.begin()+i, rev_key.begin()+i+length) == sub_v)
            return true;
    }
    return false;
}

string vectorToString(vector<int> v)
{
    string ret = "";
    for (auto i:v)
        ret += to_string(i) + " ";
    return ret;
}

char rev_char(int i)
{
    switch (i)
    {
        case 1:   return 3;
        case 2:   return 4;
        case 3:   return 1;
        case 4:   return 2;
        default:    return i;
    }
    
}
vector<int> reverse_vector(vector<int> s)
{
    vector<int> new_v;
    reverse(s.begin(), s.end());
    for (auto item: s)
        new_v.push_back(rev_char(item));
    return new_v;
}

int main()
{
    // 1 init
    int length, N;
    vector<int> key, rev_key;
    vector<string> answer;
    
    // 2 algorithm
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        int tmp;
        cin >> tmp;
        key.push_back(tmp);
    }
    key.insert(key.end(), key.begin(), key.end());  // key = orig_key * 2
    rev_key = reverse_vector(key);                  // 

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        vector<int> tmp;                            // for input
        for (int j = 0; j < length; j++)
        {
            int tmp_i;
            cin >> tmp_i;
            tmp.push_back(tmp_i);
        }
        
        if (check_subvector(length, key, rev_key, tmp))
        {
            answer.push_back(vectorToString(tmp));
        }
    }
    
    // 3 answer
    cout << answer.size() << endl;
    for (auto st: answer)
    {
        cout << st << endl;
    }
    return 0;
}