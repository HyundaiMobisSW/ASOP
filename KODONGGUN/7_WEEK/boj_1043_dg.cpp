#include <iostream>

using namespace std;

#define MAX 51

int N, M, numTruth, answer;
int p[MAX], knowTruth[MAX];
int party[MAX][MAX];

int find(int A)
{
    if (p[A] == A)
        return A;

    p[A] = find(p[A]);
    return p[A];
}

void unionAB(int A, int B)
{
    A = find(A);
    B = find(B);
    if (knowTruth[A] || knowTruth[B])
    {
        knowTruth[A] = 1;
        knowTruth[B] = 1;
    }
    p[B] = A;
}


void init()
{
    cin >> N >> M;
    for (size_t i = 1; i < N + 1; i++)
    {
        p[i] = i;
    }
    
    cin >> numTruth;
    for (size_t i = 0; i < numTruth; i++)
    {
        int num;
        cin >> num;
        knowTruth[num] = 1;
    }

    for (size_t i = 1; i < M + 1; i++)
    {
        int length;
        cin >> length;
        party[i][0] = length;

        for (size_t j = 1; j < length + 1; j++)
        {
            cin >> party[i][j];
            if (j == 1) continue;
            unionAB(party[i][j-1], party[i][j]);
            
        }
    }
}
void check()
{
    for (size_t i = 1; i < M + 1; i++)
    {
        int length = party[i][0];
        int break_chk = 0;
        for (size_t j = 1; j < length + 1; j++)
        {
            if (knowTruth[find(party[i][j])])
            {
                break_chk = 1;
                break;
            }
        }
        if (!break_chk)
        {
            answer += 1;
        }
    }
    
}

int main()
{
    init();
    check();
    cout << answer << endl;
    return 0;
}

   
