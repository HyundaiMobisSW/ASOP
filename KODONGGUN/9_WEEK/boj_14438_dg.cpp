#include <iostream>
#include <algorithm> // min
#include <climits> // INT_MAX
#include <cmath> // ceil, log2
#include <cstring>
using namespace std;

#define N_MAX 100000

int arr[N_MAX + 1];
int *tree;

void init(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }
    init(2*node,    start, (start+end)/2); // tree[2*node]
    init(2*node+1, (start+end)/2+1,  end); // tree[2*node+1]
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

void updateTree(int node, int start, int end, int index, int value)
{
    if (index < start || end < index) return;
    if (start == end)
    {
        tree[node] = arr[index] = value;
        return ;
    }
    updateTree(2*node, start, (start+end)/2, index, value); 
    updateTree(2*node+1, (start+end)/2 + 1, end, index, value);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

int findMin(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return INT_MAX;
    if (left <= start && end <= right) return tree[node];
    int lmin, rmin;
    lmin = findMin(2*node, start, (start+end)/2, left, right);
    rmin = findMin(2*node+1, (start+end)/2+1, end, left, right);
    return min(lmin, rmin);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    int h = (int)ceil(log2(N_MAX));
    int tree_size = (1 << (h+1));
    tree = (int*)malloc(sizeof(int) * tree_size + 1);
    memset(tree, 0, sizeof(int) * tree_size + 1);
    init(1, 1, N);
    int q;
    cin >> q;
    for (size_t i = 0; i < q; i++)
    {
        int query, s, e;
        cin >> query >> s >> e;
        switch (query)
        {
            case 1:
            updateTree(1, 1, N, s, e); // s: index, e: value
            break;
            case 2:
            cout << findMin(1, 1, N, s, e) << '\n';
            break;
            default:
            break;
        }
    }
    
    free(tree);
    
    return 0;
}