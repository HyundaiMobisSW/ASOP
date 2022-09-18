# 백준 2143 두 배열의 합, C++

[Link](https://www.acmicpc.net/problem/2143)

## 문제 요약
두 배열이 주어졌을때 각각의 배열로 만들수 있는 부배열의 합이 T가 되는 부배열쌍의 개수 구하기


## 접근
### 1. 생각의 흐름
각 배열의 부배열합을 구해서 저장해야한다.
원소가 1개인 것부터 모든 원소가 들어간 것 까지의 부배열을 만들고 그의 합을 저장했는데 누적합을 사용했다.
```c++
void makeArr(
	vector<int>& arr,
	vector<int>& cumArr,
	int size
)
{
	arr.assign(size, 0); // for original
	cumArr.assign(size+1, 0); // for cumulation Sum
	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
		cumArr[i+1] = cumArr[i] + arr[i];
	}
}

void findSub(
	vector<int>& cumArr, // 
	unordered_map<int,int>& tArr 
)
{
	// tArr for counting
	// key, val == sumValue, numOfKey
	for (size_t i = 0; i < cumArr.size(); i++)
	{
		for (size_t j = i+1; j < cumArr.size(); j++)
		{
			int key = cumArr[j] - cumArr[i];
			if (tArr.find(key) == tArr.end())
			{
				tArr[key] = 0;
			}
			tArr[key]++;
		}
	}
}
```

그다음은 한 쪽의 누적합을 순회하면서 반대 쪽에 값이 있는지 확인했다. 
더해서 T가 되는 부배열 쌍이 있으면 answer에 개수를 추가한다.
(누적합이 같은 경우가 있을수 있으므로 각각의 부배열 개수를 곱했다.)
```c++
for (auto p: tA)
{
	// p:key, p:val == sumValue, numOfKey
	int key = p.first;
	long long val = p.second; 
	// (tAVal * tBVal) is over int -> long long
	if (tB.count(T - key))
	{
		answer += val * tB[T - key];
	}
}
```


## 전체 코드
```c++
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
  
int T, n, m;
long long answer;
vector<int> A, B, cumA, cumB;
unordered_map<int, int> tA, tB;
  
void makeArr(
	vector<int>& arr,
	vector<int>& cumArr,
	int size
)
{
	arr.assign(size, 0);
	cumArr.assign(size+1, 0);
	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i];
		cumArr[i+1] = cumArr[i] + arr[i];
	}
}

void findSub(
	vector<int>& cumArr,
	unordered_map<int,int>& tArr
)
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
```

## 새로 알게된 것
1. 누적합