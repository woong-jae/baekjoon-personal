# [2688] 줄어들지 않아
## 💡 Algorithm
다이나믹 프로그래밍
## 📚 Logic
4자리 수의 줄어들지 않는 수 = 0 ~ 9로 시작하는 3자리수의 줄어들지 않는 수의 합이다.

즉, n 자리 줄어들지 않는 수는 n - 1 자리 수의 합으로 구할 수 있다. 그리고 중복되는 부분을 cache로 해결하면 끝이다.

```c++
long long non_decreasing_number(int length, int cur) {
    if (length == 0) return 1;
    long long& ret = cache[length][cur];
    if (ret != -1) return ret;
    
    long long res = 0;
    for (int i = 0; i < 10; i++) {
        if (i >= cur) res += non_decreasing_number(length - 1, i);
    }
    ret = res;
    
    return ret;
}
```
## ✏️ Review

64자리 숫자일 때 가능한 수가 int 형의 범위를 넘는데 그걸 생각하지 못해서 처음에 틀렸다. 자료형 생각하기 너무 귀찮다.
