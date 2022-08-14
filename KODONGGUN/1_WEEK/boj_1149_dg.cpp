#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

array<array<int, 3>, 1000> arr, memo;

int main()
{
    // 1 Initialze
    int numHouse;
    cin >> numHouse;
    for (int i = 0; i < numHouse; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    // 2 Calculate
    memo[0][0] = arr[0][0];
    memo[0][1] = arr[0][1];
    memo[0][2] = arr[0][2];
    for (int r = 1; r < numHouse; r++)
    {
        memo[r][0] = arr[r][0] + min(memo[r - 1][1], memo[r - 1][2]);
        memo[r][1] = arr[r][1] + min(memo[r - 1][0], memo[r - 1][2]);
        memo[r][2] = arr[r][2] + min(memo[r - 1][0], memo[r - 1][1]);
    }

    // 3 Print answer
    cout << *(min_element(memo[numHouse - 1].begin(), memo[numHouse - 1].end())) << endl;
    return 0;
}