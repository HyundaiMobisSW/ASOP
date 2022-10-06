#include <iostream>
#include <stack>
#include <string> // string
#include <algorithm> // reverse
using namespace std;

int N, K;
string strNumber;

void check()
{
    int break_i = -1;
    string tmpStrNumber;
    stack<char> s;
    for (int i=0; i<N; i++) // char ch
    {
        char ch = strNumber[i];
        if (s.empty())
        {
            s.push(ch);
            continue;
        }
        
        while (!s.empty())
        {
            if (s.top() < ch)
            {
                s.pop();
                K--;
                if (K == 0) 
                {
                    break_i = i;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (K == 0)
        {
            break;
        }
        s.push(ch);
    }
    
    // stack -> tmpStrNumber
    while(!s.empty())
    {
        tmpStrNumber += s.top();
        s.pop();
    }
    reverse(tmpStrNumber.begin(), tmpStrNumber.end());
    if (break_i != -1)
    {
        for (int i = break_i; i < N; i++)
        {
            tmpStrNumber += strNumber[i];
        }
    }
    
    // renew strNumber, N
    strNumber = "";
    for (size_t i = 0; i < tmpStrNumber.size() - K; i++)
    {
        strNumber += tmpStrNumber[i];
    }
    return;
}

int main()
{
    cin >> N >> K;
    cin >> strNumber;

    check();

    cout << strNumber << endl;

    return 0;
}