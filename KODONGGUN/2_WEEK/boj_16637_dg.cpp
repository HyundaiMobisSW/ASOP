#include <iostream>
#include <string> // to_string, stoi
#include <vector>
#include <stack>
#include <climits> // int32_min
#include <algorithm> // min
// #include <bitset> // cout << bitset<10>(num)

using namespace std;

int check(int bitmask);
int pre_cal(int num1, char op, int num2);
int calculate(int bitmask,vector<int> number, vector<char> op);

int N, answer = INT32_MIN;
string exp;

int main()
{
    vector<int> number;
    vector<char> op;
    cin >> N >> exp;
    if (N==1) 
    {
        cout << exp << endl;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        if (i % 2)      op.push_back(exp[i]);
        else            number.push_back(((int)exp[i] - (int)'0'));
    }

    // bruteforce
    for (int i = 0; i < (1 << (N/2)) - 1; i++)
    {
        /* code */
        if (!check(i)) continue;
        answer = max(answer, calculate(i, number, op));
    }

    cout << answer << endl;
    
    return 0;
}


int check(int bitmask)
{
    int flag = 0;
    while (bitmask)
    {
        if (flag && (bitmask % 2)) return false;
        flag = (bitmask % 2);
        bitmask >>= 1;
    }
    return true;
}

int pre_cal(int num1, char op, int num2)
{
    switch (op)
    {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    default:  return INT32_MIN;
    }
}


int calculate(int bitmask,vector<int> number, vector<char> op)
{
    // for (auto item: number) cout << item << " "; cout << endl;
    // for (auto item: op) cout << item << " "; cout << endl;
    

    stack<int> new_number;
    stack<char> new_op;
    // cout << bitset<10> (bitmask) << endl;
    for (int i=0; i<N/2; i++)
    {
        if(bitmask % 2)
        {
            char tmp_op = op.back();            op.pop_back();
            int tmp_num1 = number.back();       number.pop_back();
            int tmp_num2 = number.back();       number.pop_back();
            int pre_num = pre_cal(tmp_num2, tmp_op, tmp_num1);
            number.push_back(pre_num);
        }
        else
        {
            new_number.push(number.back());     number.pop_back();
            new_op.push(op.back());             op.pop_back();
            // cout << "new_num: " << new_number.top() << " new_op: " << new_op.top() << endl;
        }
        bitmask >>= 1;
    }

    int ret = number.back();                    number.pop_back();
    // cout << "ret: " << ret << endl;
    
    while (!new_number.empty())
    {
        char tmp_op = new_op.top();             new_op.pop();
        int tmp_num1 = new_number.top();        new_number.pop();
        ret = pre_cal(ret, tmp_op, tmp_num1);
        // cout << ret << "/" << tmp_op << " " << tmp_num1 << endl;
    }
    // cout << "ret: " << ret << endl;
    return ret;
}

