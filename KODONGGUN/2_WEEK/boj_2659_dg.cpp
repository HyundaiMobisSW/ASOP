#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, int> clockNumber;
int findMinClockNumber(int a, int b, int c, int d)
{
    return min({
        1000*a + 100*b + 10*c + d,
        1000*b + 100*c + 10*d + a,
        1000*c + 100*d + 10*a + b,
        1000*d + 100*a + 10*b + c
    });
}
int findClockNumber(int(&arr)[4])
{
    int ret = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 1; k <= 9; k++)
            {
                for (int l = 1; l <= 9; l++)
                {
                    int minClockNumber = findMinClockNumber(i,j,k,l);
                    if (clockNumber.find(minClockNumber) == clockNumber.end())
                    {
                        ret++;
                        clockNumber[minClockNumber] = ret;
                    }
                    
                    if (arr[0] == i && arr[1] == j && arr[2] == k && arr[3] == l)   
                    {
                        return clockNumber[minClockNumber];
                    }
                }
            }
        }
    }
    
    return ret;
}

int main()
{
    // 1 init
    int arr[4], answer;
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    
    // 2 calculate
    answer = findClockNumber(arr);

    // 3 answer
    cout << answer << endl;
    return 0;
}