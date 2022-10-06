#include <iostream>
#include <vector>
#include <queue> // priority_queue
using namespace std;

#define N_MAX 1001

typedef struct {
    int w;
    int s;
    int e;
} EDGE;

struct compare {
    bool operator() (const EDGE A, const EDGE B) 
    {
        return A.w > B.w;
    }
};

priority_queue <EDGE, vector<EDGE>, compare> pq;

int N, M;
int p[N_MAX]; //parent(root)
int r[N_MAX]; //rank

void init()
{
    cin >> N;
    cin >> M;
    int s, e, w;
    for (size_t i = 0; i < M; i++)
    {
        cin >> s >> e >> w;
        pq.push({w, s, e});
    }
    
    // for checking cycle
    for (size_t i = 0; i <= N; i++)
    {
        p[i] = i;
    }
    
}

int myFind(int A)
{
    if (p[A] == A) return A;

    p[A] = myFind(p[A]);
    return p[A];
}

void myUnion(int A, int B)
{
    A = myFind(A);
    B = myFind(B);
    if (A == B) return;
    if (r[A] < r[B])        
        p[A] = B;
    else
    {
        p[B] = A;
        if (r[A] == r[B])
            r[A]++;
    }
}

int kruskal() // pq sorted by weight
{
    int ret = 0; // 100,000*10,000 = 1,000,000,000

    while(!pq.empty())
    {
        EDGE cur = pq.top();
        pq.pop();

        // making a cycle, skip;
        if (myFind(cur.s) == myFind(cur.e)) continue; 
        myUnion(cur.s, cur.e);
        ret += cur.w;

        // cout << cur.s << '\t' << cur.e << '\t' << cur.w << endl;
    }

    return ret;
}


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    cout << kruskal() << endl;
    return 0;
}