# [1563] 개근상
## 💡Algorithm
- DP
## 📚Logic
부분문제
- 출석한다
- 지각한다
- 결석한다

```c++
int combinations(int cur, int l, int a) {
    if (cur == n) return 1;
    int &ret = cache[cur][l][a];
    if (ret != -1) return ret;
    
    ret = 0;
    
    if (l < 1) ret += combinations(cur + 1, l + 1, 0);
    ret += combinations(cur + 1, l, 0);
    if (a < 2) ret += combinations(cur + 1, l, a + 1);
    ret = ret % 1000000;
    
    return ret;
}
```
## 📝Review
어렵지 않은 DP문제
