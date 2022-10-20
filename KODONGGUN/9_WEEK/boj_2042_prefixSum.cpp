#include <iostream>
#include <vector>
#include <cmath> // ceil, log2
#include <cstring>


#define N_MAX 1000000
using namespace std;

long long arr[N_MAX + 1];
long long *tree;

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }
    
    init(2 * node, start, (start + end)/2);   // tree[2 * node]
    init(2 * node + 1, (start + end)/2 + 1, end); // tree[2 * node + 1]
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    
}
void updateNode(int node, int start, int end, long long index, long long num)
{
    if (index < start || index > end) return;
    if (start == end)
    {
        arr[index] = tree[node] = num;
        return;
    }
    updateNode(2*node,   start, (start+end)/2, index, num);
    updateNode(2*node+1, (start+end)/2+1, end, index, num);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    
}

long long calculatePrefixSum(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    long long lsum, rsum;
    lsum = calculatePrefixSum(node*2,   start, (start+end)/2, left, right);
    rsum = calculatePrefixSum(node*2+1, (start+end)/2+1, end, left, right);
    return lsum + rsum;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); 

    int N, M, K;
    cin >> N >> M >> K;

    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    int h = (int)ceil(log2(N_MAX));
    int tree_size = (1 << (h+1));
    tree = (long long*)malloc(sizeof(long long) * tree_size + 1);
    memset(tree, 0, sizeof(long long) * tree_size + 1);
    

    init(1, 1, N);
    for (size_t i = 0; i < M + K; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >>c;
        switch (a)
        {
            case 1:
            updateNode(1, 1, N, b, c);
            break;
            case 2:
            cout << calculatePrefixSum(1, 1, N, b, (int)c) << '\n';
            break;
            default:
            break;
        }
    }
    free(tree);

    return 0;
}
