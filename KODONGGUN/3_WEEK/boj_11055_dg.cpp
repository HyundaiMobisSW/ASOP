#include <iostream>
#include <algorithm> // max

#define MAX 1000

using namespace std;

int N, answer;
int arr[MAX];
int memo[MAX][MAX];

void printMemo(int size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << arr[i] << "/\t";
        for (size_t j = 0; j < size; j++)
        {
            cout << memo[i][j] << "\t";
        }
        cout << endl;
    }    
    cout << endl;
}

int main()
{
    // 1 init
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    // 2 dynamic programming with memoization
    
    for (int i = 0; i < N; i++)
    {
        answer = max(answer, arr[i]);
        for (int j = i; j < N; j++)
        {   

            if (arr[i] < arr[j])
            {
                if (i > 0)
                {
                    memo[i][j] = max(memo[i - 1][j], memo[i][i] + arr[j]);
                }
                else
                {
                    memo[i][j] = arr[i] + arr[j];
                }
                // memo[i][j] = ((i > 0) ? memo[i-1][j] : arr[j]) + arr[i]; 
                // m[j] = ((i > 0) ? m[j] : arr[j]) + arr[i]; 
            } 
            else if (arr[i] == arr[j])
            {
                if (i>0)
                {
                    memo[i][j] = max(arr[i], memo[i-1][j]);
                }
                else
                {
                    memo[i][j] = arr[i];
                }
            }
            else // arr[i] > arr[j] 
            {
                if (i > 0)
                {
                    memo[i][j] = memo[i-1][j];
                }
                else 
                {
                    memo[i][j] = arr[j];
                }
                // memo[i][j] = (i > 0) ? memo[i-1][j] : arr[i];
                // m[j] = (i > 0) ? m[j] : arr[i];
            }
            answer = max(answer, memo[i][j]);
        }
    }
    printMemo(N);

    // for (int i = 0; i < N; i++) cout << m[i] << " ";
    // cout << endl;

    // 3 answer
    cout << answer << endl;
    return 0;
}