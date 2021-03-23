# [4811] 알약
## 💡Algorithm
- DP
## 📚Logic
알약을 뽑는 경우의 수는 두가지이다.
1. 완전한 알약을 뽑는다.
    - 완전한 알약 하나를 줄이고, 반쪽짜리를 하나 늘린다.
2. 반쪽짜리 알약을 뽑는다.
    - 반쪽짜리 하나를 제거한다.

기저사례는 두 알약의 개수가 0이 될때이다.
```c++
long long all_case(int full, int half) {
    if (full == 0 && half == 0) return 1;
    long long &ret = cache[full][half];
    if (ret != -1) return ret;
    
    ret = 0;
    if (full > 0) ret += all_case(full - 1, half + 1);
    if (half > 0) ret += all_case(full, half - 1);
    
    return ret;
}
```
## 📝Review
쉽다!
