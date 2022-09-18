#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> m;
long long N; // max(N) = 10^12
int P, Q; // max(P), max(Q) = 10^9

long long find(long long number);

int main()
{
    cin >> N >> P >> Q;

    m[0] = 1;

    cout << find(N) << endl;
    return 0;
}

long long find(long long number){
    if (m.find(number)!=m.end())
    {
        return m[number];
    }
    m[number] = find(number/P) + find(number/Q);
    return m[number];
}