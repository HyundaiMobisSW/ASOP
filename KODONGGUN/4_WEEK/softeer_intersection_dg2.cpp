#include <iostream>
#include <queue>
#include <vector>
#include <cstring> // memset
#include <algorithm> // min
using namespace std;

#define MAX_SIZE 200000
#define MAX_TIME 1000000001

int N;                      // size
int answer[MAX_SIZE];
queue<pair<int, int>> A, B, C, D; // for input  0~3:top-right-bottom-left 

int main()
{
    // 1 init
    cin >> N;
    memset(answer, -1, sizeof(int) * N);
    for (size_t i = 0; i < N; i++)
    {
        int time;
        char road;

        cin >> time >> road; 
        switch (road)
        {
            case 'A': A.push({i, time}); break;
            case 'B': B.push({i, time}); break;
            case 'C': C.push({i, time}); break;
            case 'D': D.push({i, time}); break;
            default:                     break;
        }
    }

    // 2 algorithm
    int t = min({
        (A.empty()) ? MAX_TIME : A.front().second,
        (B.empty()) ? MAX_TIME : B.front().second,
        (C.empty()) ? MAX_TIME : C.front().second,
        (D.empty()) ? MAX_TIME : D.front().second,
    });
    
    while (!A.empty() || !B.empty() || !C.empty() || !D.empty())
    {
        // update min time
        int tmp_A = MAX_TIME; // 1e9 + 1
        int tmp_B = MAX_TIME; // 1e9 + 1
        int tmp_C = MAX_TIME; // 1e9 + 1
        int tmp_D = MAX_TIME; // 1e9 + 1
        
        if (!A.empty() && A.front().second < tmp_A)     tmp_A = A.front().second;
        if (!B.empty() && B.front().second < tmp_B)     tmp_B = B.front().second;
        if (!C.empty() && C.front().second < tmp_C)     tmp_C = C.front().second;
        if (!D.empty() && D.front().second < tmp_D)     tmp_D = D.front().second;
        
        if(tmp_A > t && tmp_B > t && tmp_C > t && tmp_D > t)
            t = min({tmp_A, tmp_B, tmp_C, tmp_D});

        // 1 check arrival time 
        int checkA = 0;
        if (!A.empty() && A.front().second <= t)
        {
            // 2 check right road is empty  
            if (D.empty() || D.front().second > t) 
            {
                checkA = 1;
            }
        }

        int checkB = 0;
        if (!B.empty() && B.front().second <= t)
        {
            if (A.empty() || A.front().second > t) 
            {
                checkB = 1;
            }
        }

        int checkC = 0;
        if (!C.empty() && C.front().second <= t)
        {
            
            if (B.empty() || B.front().second > t) 
            {
                checkC = 1;
            }
        }
        int checkD = 0;
        if (!D.empty() && D.front().second <= t)
        {
            
            if (C.empty() || C.front().second > t) 
            {
                checkD = 1;
            }
        }
        

        // check deadlock 
        if (!checkA && !checkB && !checkC && !checkD)
        {
            break; // algorithm break
        }
        
        // not deadlock
        if (checkA)
        {
            answer[A.front().first] = t;
            A.pop();
        }
        if (checkB)
        {
            answer[B.front().first] = t;
            B.pop();
        }
        if (checkC)
        {
            answer[C.front().first] = t;
            C.pop();
        }
        if (checkD)
        {
            answer[D.front().first] = t;
            D.pop();
        }
        
        t += 1;
    }
    
    // 3 answer
    for (int i = 0; i < N; i++)
    {
        cout << answer[i] << '\n';
    }
    cout << endl;

    return 0;
}
