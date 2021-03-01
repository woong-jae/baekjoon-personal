# [9095] 1, 2, 3 더하기
## 💡Algorithm
다이나믹 프로그래밍
## 📚Logic
정수 4를 1, 2, 3의 합으로 나타낼 수 있는 경우의 수는 1, 2, 3을 1, 2 ,3의 합으로 나타낼 수 있는 경우의 수를 합하면 된다.

즉, N은 N - 1, N - 2, N - 3 을 1, 2, 3의 합으로 나타낼 수 있는 경우의 수의 합으로 구할 수 있다.

```c++
int make_number(int a) {
    if (a == 0) return 1;
    int& ret = cache[a];
    if(ret != -1) return ret;
    
    int res = 0;
    for (int i = 1; i <= 3; i++) {
        if (a - i >= 0) res += make_number(a - i);
    }
    ret = res;
    
    return ret;
}
```
## 📝Review
기본적인 DP문제. 별로 어렵지 않게 풀었다.
