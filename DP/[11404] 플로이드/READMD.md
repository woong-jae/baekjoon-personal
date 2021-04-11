# [11404] 플로이드
## 💡Algorithm
- DP
- Floyd algorithm
## 📚Logic
플로이드 알고리즘을 사용한다.
```c++
void floyd() {
    //C[0]을 초기화
    for (int i = 0; i < V; i++) adj[i][i] = 0;
    // C[k-1]이 있으면 C[k]를 계산할 수 있다.
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}
```
## 📝Review
플로이드 알고리즘을 적용하는 문제.
