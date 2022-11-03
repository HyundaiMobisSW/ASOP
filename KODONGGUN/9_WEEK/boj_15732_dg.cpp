#include <iostream>
#include <cstring>
#include <algorithm> // min
using namespace std;

typedef struct  {
    int A; int B; int C;
} NODE;
NODE *rules;
int N, K, D;

int find(int boxIndex)
{
    long long cnt = 0;
    for (size_t i = 0; i < K; i++)
    {
        if (boxIndex < rules[i].A) continue; // 
        cnt += ((min(rules[i].B, boxIndex) - rules[i].A) / rules[i].C) + 1;
    }
    return cnt >= D;
}

int main()
{
    cin >> N >> K >> D;
    rules = (NODE*)malloc(sizeof(NODE)*N+1);
    for (size_t i = 0; i < K; i++)
    {
        NODE n;
        cin >> n.A >> n.B >> n.C;
        rules[i] = n;
    }

    int l = 0, r = N;
    while (l <= r)
    {
        int m = (l+r)/2; // find index 

        if (find(m)) // how many does the box[index] have dotory
        {
            r = m - 1; // decrease right range 
        }
        else 
        {
            l = m + 1; // decrease left range
        }
    }

    cout << l << endl;
    
    return 0;
}