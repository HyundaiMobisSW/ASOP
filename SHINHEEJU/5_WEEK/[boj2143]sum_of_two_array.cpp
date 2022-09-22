#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sum_a, sum_b;
int t, n, m, sum;
int a[1001], b[1001];
long long answer;
int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    // 입력
    cin >> t;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> b[i];
    }

    // A의 부배열 합 저장
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
            sum += a[j];
            sum_a.push_back(sum);
        }
    }

    // B의 부배열 합 저장
    for(int i=0; i<m; i++){
        sum = 0;
        for(int j=i; j<m; j++){
            sum += b[j];
            sum_b.push_back(sum);
        }
    }

    //sort(sum_a.begin(), sum_a.end());
    sort(sum_b.begin(), sum_b.end());


    // for(int i=0; i<sum_a.size(); i++){
    //     for(int j=0; j<sum_b.size(); j++){
    //         //cout << sum_a[i] << " " << sum_b[j] << endl;
    //         long long result = sum_a[i]+sum_b[j];
    //         if(result < t) continue;
    //         else if(result == t) answer +=1;
    //         else{
    //             break;
    //         }
    //     }
    // }
    for(int i=0; i<sum_a.size(); i++){
        //answer += count(sum_b.begin(), sum_b.end(), t-sum_a[i]);
        answer += (upper_bound(sum_b.begin(), sum_b.end(), t-sum_a[i]) - lower_bound(sum_b.begin(), sum_b.end(), t-sum_a[i]));
    }
    
    cout << answer;
    return 0;
}

// 시간초과
// 틀렸습니다 (answer -> int)
