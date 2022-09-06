#include<iostream>
#include <vector>

using namespace std;

int N;
int x;
char y;
vector<pair<int, char>> v;

int main(int argc, char** argv)
{
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	return 0;
}