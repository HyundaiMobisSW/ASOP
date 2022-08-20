#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct node {
    int red;
    int green;
    int blue;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<node> price(n);

    for (int i = 0; i < n; i++) {
        cin >> price[i].red >> price[i].green >> price[i].blue;
    }

    vector<node> result(n);
    result[0] = price[0];

    for (int i = 1; i < n; i++) {
        result[i].red = min(result[i - 1].green, result[i - 1].blue) + price[i].red;
        result[i].green = min(result[i - 1].red, result[i - 1].blue) + price[i].green;
        result[i].blue = min(result[i - 1].red, result[i - 1].green) + price[i].blue;
    }

    cout << min(min(result[n-1].red, result[n-1].green), result[n-1].blue);
}
