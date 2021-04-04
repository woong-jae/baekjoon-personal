# [2342] Dance Dance Revolution
## 💡Algorithm
- DP
## 📚Logic
부분 문제를 왼발을 움직였을때와 오른발을 움직였을 때로 나눌 수 있다.
```c++
int min_power(int cur, int left, int right) {
    if (cur >= input.size()) return 0;
    int &ret = cache[cur][left][right];
    if (ret != -1) return ret;
    
    // 왼쪽발을 움직인다.
    ret = min_power(cur + 1, input[cur], right) + cal(left, input[cur]);
    // 오른쪽발을 움직인다.
    ret = min(ret, min_power(cur + 1, left, input[cur]) + cal(right, input[cur]));
    
    return ret;
}
```
## 📝Review
어렵지 않은 문제지만, 힘을 계산하는 부분에서 예외가 하나 있는것을 찾지 못해서 한참을 해맸다... 잘하자
