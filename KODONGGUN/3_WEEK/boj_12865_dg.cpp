#include <iostream>

#include <algorithm>
#include <vector>
using namespace std;

int N, K, answer;
// int W[101], V[101];
int memo[101][100001];

void printMemo(int sizeR, int sizeC)
{
    for (int i = 0; i < sizeR; i++)
    {
        for (int j = 0; j < sizeC; j++)
        {
            cout << memo[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<pair<int,int>> item;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int w, v;
        cin >> w >> v;
        item.push_back({w, v});
    }
    
    for (size_t i = 1; i < N+1; i++)
    {
        for (size_t w = 1; w < K+1; w++)
        {
            if (item[i-1].first > w)
            {
                memo[i][w] = memo[i-1][w];
            }
            else 
            {
                memo[i][w] = max(
                    memo[i-1][w],
                    memo[i-1][w - item[i-1].first] + item[i-1].second
                );
            }
        }
    }
    // printMemo(N+1, K+1);
    answer = memo[N][K];
    cout << answer << endl;
    return 0;
}


// #include <iostream>
// #include <algorithm> // max
// #define MAX_SIZE 100
// using namespace std;

// int N, K, answer;
// int W[MAX_SIZE], V[MAX_SIZE], visit[MAX_SIZE];
// void backtrack(int ind, int total_w, int total_v);

// int main()
// {
//     cin >> N >> K;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> W[i] >> V[i];
//     }
//     backtrack(0, 0, 0);
//     cout << answer << endl;
//     return 0;
// }

// void backtrack(int ind, int total_w, int total_v)
// {
//     if (ind == N)
//     {
//         answer = max(answer, total_v);
//         return;
//     }

//     for (int i = 0; i < N; i++)
//     {
//         if (visit[i]) continue;
//         if (total_w + W[i] <= K)
//         {
//             visit[i] = 1;
//             backtrack(ind + 1, total_w + W[i], total_v + V[i]);
//             visit[i] = 0;
//         }
//         backtrack(ind + 1, total_w, total_v);
//     }
// }