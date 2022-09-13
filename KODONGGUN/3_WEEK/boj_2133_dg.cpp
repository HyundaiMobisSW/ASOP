#include <iostream>

#define SIZE 31
using namespace std;

int memo[SIZE] = {0, 0, 3,};

int main()
{
    for (int i = 4; i < SIZE; i += 2)
    {
        memo[i] = memo[i - 2] * 3 + 2;
        for (int j = i - 2; j > 2; j -= 2)
        {
            memo[i] += 2 * memo[i-j];
        }
    }

    int N;
    cin >> N;
    cout << memo[N] << endl;
    
    return 0;
}