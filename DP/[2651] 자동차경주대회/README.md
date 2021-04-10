# [2651] 자동차경주대회
## 💡Algorithm
- DP
## 📚Logic
T[k]를 출발점에서 k번째 정비소까지 가는데 필요하 최소정비시간이라 하자. 

T[k]는 k까지 한번에 올 수 있는 정비소 중 가장 정비시간이 짧게 걸리는 정비소에 k의 정비시간을 더한 값이 된다.

```c++
#include <iostream>
#include <vector>

using namespace std;
long long T[102], t[102];
int p[102];

int main() {
    int max_reach, n;
    cin >> max_reach >> n;
    vector<long long> dist(n + 2);
    dist[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        cin >> dist[i];
        dist[i] += dist[i - 1];
        T[i] = 1ll << 40;
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    
    T[0] = 0; p[0] = -1;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j < i; j++) {
            if (dist[i] - dist[j] <= max_reach && (T[i] > T[j] + t[i])) {
                T[i] = T[j] + t[i];
                p[i] = j;
            }
        }
    }
    vector<int> path; int cur = n + 1;
    while (1) {
        int next = p[cur];
        if (next == 0) break;
        path.push_back(next);
        cur = next;
    }
    
    cout << T[n + 1] << '\n' << path.size() << '\n';
    if (path.size()) {
        for (int i = (int)path.size() - 1; i >= 0; i--) {
            cout << path[i] << ' ';
        }
    }
}
```
## 📝Review
문제는 안어려웠는데, 망할놈의 경계값 오류 때문에 시간을 많이 잡아먹었다. 짜증난다.
