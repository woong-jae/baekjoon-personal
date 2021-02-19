# [1937] 욕심쟁이 판다
## 📕 Algorithm
다이나믹 프로그래밍
## 📗 Logic
그래프의 모든 노드를 순회한다. 노드마다 조건에 맞는 노드로 깊이 우선 탐색으로 최대 수명을 계산한다.
```c++
int dayToLive(int r, int c) {
    int& ret = cache[r][c];
    if(ret != -1) return ret;
    
    int res = 1;
    
    for (int i = 0; i < 4; i++) {
        if(0 <= r + y[i] && r + y[i] < n && 0 <= c + x[i] && c + x[i] < n && bamboo[r][c] < bamboo[r + y[i]][c + x[i]]) {
            res = max(res, dayToLive(r + y[i], c + x[i]) + 1);
        }
    }
    ret = res;
    
    return ret;
}
```
## 📘 Review
별로 어렵지 않았다. 그래프에서 사용하는 DP 문제가 익숙해져서 빨리 풀 수 있었다.
