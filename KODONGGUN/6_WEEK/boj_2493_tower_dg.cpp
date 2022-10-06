#include <iostream>
#include <stack>

#define MAX_N 500000
using namespace std;


int N;
int arr[MAX_N];

int main()
{
    
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> arr[i];
    
    stack<pair<int,int>> s; // value, index
    // s.push({-1, 0});
    for (size_t i = 0; i < N; i++)
    {
        if (s.empty())
        {
            cout << "0 ";
            s.push({arr[i], i});
        }
        else 
        {
            if (s.top().first > arr[i]) // > or >=
            {
                cout << s.top().second + 1 << " ";
                s.push({arr[i], i});
                continue;
            }
            while (!s.empty() && s.top().first < arr[i]) // < or <=
            {
                s.pop();
            }
            if (s.empty())
            {
                cout << "0 ";
            }
            else
            {
                cout << s.top().second + 1 << " ";
            }
            s.push({arr[i], i});
        }
    }
    cout << endl;
    
    
    return 0;
}