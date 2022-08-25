#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
void inputIntoSet(set<int>& s, int size)
{
    for (int i = 0; i < size; i++)
    {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }
}
int main()
{
    int N, M;
    set<int> s1, s2, answer;
    cin >> N >> M;
    inputIntoSet(s1, N);
    inputIntoSet(s2, M);
    

    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(answer, answer.end()));
    set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), inserter(answer, answer.end()));
    
    cout << answer.size() << endl;
    return 0;
}