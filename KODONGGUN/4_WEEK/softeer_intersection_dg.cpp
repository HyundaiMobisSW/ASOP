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
queue<pair<int, int>> roads[4]; // for input  0~3:top-right-bottom-left 

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
        roads[road-'A'].push({i, time});
    }

    // 2 algorithm
    int t = min({
        (roads[0].empty()) ? MAX_TIME : roads[0].front().second,
        (roads[1].empty()) ? MAX_TIME : roads[1].front().second,
        (roads[2].empty()) ? MAX_TIME : roads[2].front().second,
        (roads[3].empty()) ? MAX_TIME : roads[3].front().second,
    });
    
    while (!roads[0].empty() || !roads[1].empty() || !roads[2].empty() || !roads[3].empty())
    {
        // update min time
        int tmp_t[4] = {
            MAX_TIME, // 1e9 + 1
            MAX_TIME, // 1e9 + 1
            MAX_TIME, // 1e9 + 1
            MAX_TIME, // 1e9 + 1
        };

        for (int i = 0; i < 4; i++)
        {
            if (roads[i].empty()) continue;
            if (roads[i].front().second < tmp_t[i])
                tmp_t[i] = roads[i].front().second;
        }
        if (tmp_t[0] > t && tmp_t[1] > t && tmp_t[2] > t && tmp_t[3] > t)
            t = min({tmp_t[0],tmp_t[1],tmp_t[2],tmp_t[3]});

        // checkRoad(check, t);
        int check[4] = {0, };
        for (int i = 0; i < 4; i++)
        {
            // 1 check arrival time 
            if (roads[i].empty())               continue;
            if (roads[i].front().second > t)    continue;
            
            // 2 check right road is empty  
            // if top(road[0]), check right(road[3], top's right)
            int right = (i + 3) % 4;
            if (!roads[right].empty() && roads[right].front().second <= t) continue;
            check[i] = 1;
        }

        // if (isDeadlock(check, t))
        // int deadlock = check[0] + check[1] + check[2] + check[3]; if deadlock == 0,
        if (!check[0] && !check[1] && !check[2] && !check[3])
        {
            break; // algorithm break
        }
        
        // not deadlock
        for (int i = 0; i < 4; i++)
        {
            if (!check[i]) continue;
            // if(roads[i].empty()) continue;
            answer[roads[i].front().first] = t;
            roads[i].pop();
        }
        
        t += 1;
    }
    
    // 3 answer
    for (int i = 0; i < N; i++)
    {
        cout << answer[i] << '\n';
    }
    

    return 0;
}