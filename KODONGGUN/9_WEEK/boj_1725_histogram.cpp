#include <iostream>
#include <cmath> //ceil, log2
#include <cstring> // malloc, memset
#include <algorithm> // max, min
#define MAX 100000

using namespace std;

int *arr, *tree;


void init(int node, int start, int end)
{
    // leaf node에 가장 작은 높이를 가지는 인덱스 저장
    if (start == end)
    {
        tree[node] = start;
        return ;
    }
    init(2*node, start, (start+end)/2); // tree[2*node]
    init(2*node+1, (start+end)/2+1, end);// tree[2*node+1]
    if (arr[tree[node*2]] <= arr[tree[node*2+1]]) 
        tree[node] = tree[node*2];
    else
        tree[node] = tree[node*2 + 1];
}

int findMinIndex(int node, int start, int end, int left, int right)
{
    // l, r 사이에서 가장 작은 높이를 가지는 index 반환
    if (right < start || end < left) return 0; // error
    if (left <= start && end <= right) return tree[node];
    int m1, m2;
    m1 = findMinIndex(2*node, start, (start+end)/2, left, right);
    m2 = findMinIndex(2*node+1, (start+end)/2+1, end, left, right);
    if (!m1) return m2;
    if (!m2) return m1;
    if (arr[m1] <= arr[m2])
        return m1;
    else 
        return m2;
}

int findMax(int start, int end, int left, int right)
{
    int min_index = findMinIndex(1, start, end, left, right);
    int area = (right - left + 1) * arr[min_index];
    if (min_index + 1 <= right)
    {
        int tmpArea = findMax(start, end, min_index+1, right);
        area = max(area, tmpArea);
    }
    if (min_index - 1 >= left)
    {
        int tmpArea = findMax(start, end, left, min_index-1);
        area = max(area, tmpArea);
    }
    return area;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h+1));
    arr = (int*)malloc(sizeof(int) * N+1);
    tree = (int*)malloc(sizeof(int) * tree_size+1);

    for (size_t i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    init(1, 1, N);
    cout << findMax(1, N, 1, N) << endl;

    free(arr);
    free(tree);
    return 0;
}