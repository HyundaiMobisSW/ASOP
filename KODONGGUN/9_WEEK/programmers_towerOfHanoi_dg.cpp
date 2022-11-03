#include <string>
#include <vector>
using namespace std;

vector<vector<vector<int>>> memo;

int pow2(int n)
{
    if (n<=0) return 1;
    int d = pow2(n/2);
    if (n%2)
        return d*d*2;
    else
        return d*d;
}

int p1(int num)
{
    switch(num)
    {
        case 2: return 3;
        case 3: return 2;
        default: return num;
    }
}
int p2(int num)
{
    switch (num)
    {
        case 1: return 2;
        case 2: return 3;
        case 3: return 1;
        default: return num;
    }
}

vector<vector<int>> solution(int n) {
    for (int i = 0; i <= n; i++)
    {
        vector<vector<int>> tmp (pow2(i)-1, {2,0});
        memo.push_back(tmp);
        if (i == 0) continue;
        
        // 1 move 1 to 2
        int prev_size = memo[i-1].size();
        for (int j = 0; j < prev_size; j++)
        {
            memo[i][j] = {
                p1(memo[i-1][j][0]),
                p1(memo[i-1][j][1])
            };
        }
        // 2 middle of array  => [1,3]
        memo[i][prev_size] = {1, 3};
        
        // 3 move 2 to 3
        for (int j = 0; j < prev_size; j++)
        {
            memo[i][prev_size + j + 1] = {
                p2(memo[i][j][0]), p2(memo[i][j][1])
            };
        }     
    }
    
    return memo[n];
}