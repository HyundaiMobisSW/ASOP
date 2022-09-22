#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int T, n, m;
long long answer;
vector<int> A, B, cumA, cumB;
unordered_map<int, int> tA, tB;

void makeArr(vector<int>& arr, vector<int>& cumArr, int size)
{
    arr.assign(size, 0);
    cumArr.assign(size+1, 0);
    for (size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
        cumArr[i+1] = cumArr[i] + arr[i];
    }
}
void findSub(vector<int>& cumArr, unordered_map<int,int>& tArr)
{
    for (size_t i = 0; i < cumArr.size(); i++)
    {
        for (size_t j = i+1; j < cumArr.size(); j++)
        {
            int key = cumArr[j] - cumArr[i];
            if (tArr.find(key) == tArr.end())
                tArr[key] = 0;
            tArr[key]++;
        }
    }
}

void init()
{
    cin >> T;
    cin >> n;
    makeArr(A, cumA, n);
    findSub(cumA, tA);
    cin >> m;
    makeArr(B, cumB, m);
    findSub(cumB, tB);
}

void findAnswer()
{
    for (auto p: tA)
    {
        int key = p.first;
        long long val = p.second;
        if (tB.count(T - key))
        {
            answer += val * tB[T - key];
        }
    }
}

int main()
{
    init();
    findAnswer();
    cout << answer << endl;

    return 0;
}
