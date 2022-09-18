# 백준 1351 무한수열, C++

[Link](https://www.acmicpc.net/problem/1351)

## 문제 요약
무한 수열 A의 N 번째 값 구하기
- A0 = 1, Ai = A⌊i/P⌋ + A⌊i/Q⌋ (i ≥ 1)
- (⌊x⌋는 x를 넘지 않는 가장 큰 정수이다.)

## 접근
### 1.  구현
주어진 조건에 대해 구현하기.
N 에 대해서 구해야하므로 Top Down 방식이 나을듯 했다.
그리고 max(N) = 10^12 이므로 꽤 많은 연산이 있을 것이고 중복 되는 값이 있을 것이므로 Dynamic Programming으로 구현한다.

DP을 위해 배열을 사용해서 메모리를 잡으면 공간복잡도는 O(N)이나 최대값이 4\*10^12이므로 메모리 제한을 초과한다.
-> 해시(unordered_map)를 사용해서 필요한 값만 저장하는 방식으로 진행한다.

Top Down 구현할때도 함수의 return 값을 `long long`으로 잡아야할듯 하다. 입력이 `10^12 2 2` 라면 `int`로 부족할거 같다.(추측이었지만 int find로 바꿨을때 실패했다.)

## 전체 코드
```c++
#include <iostream>
#include <unordered_map>
  
using namespace std;
  
unordered_map<long long, long long> m;
long long N; // max(N) = 10^12
int P, Q; // max(P), max(Q) = 10^9
 
long long find(long long number){
	if (m.find(number) != m.end())
		return m[number];
	
	m[number] = find(number/P) + find(number/Q);
	return m[number];
}

int main()
{
	m[0] = 1;
	cin >> N >> P >> Q;  

	cout << find(N) << endl;
	return 0;
}
 
```

## 새로 알게된 것
1. X