# [1912] 연속합
## 💡Algorithm
다이나믹 프로그래밍
## 📚Logic
- Bottom-Up

이전까지 이어온 수열과 수열에 현재 숫자를 더한것을 비교한다. 이전 수열보다 크다면, 더한것을 담고 아니면 수열을 현재부터 다시 시작한다.
```c++
max_val = dp[0];
    for (int i = 1; i < n; i++) {
        if (sequence[i] + dp[i - 1] > sequence[i]) dp[i] = sequence[i] + dp[i - 1];
        else dp[i] = sequence[i];
        max_val = max(max_val, dp[i]);
    }
```
## 📝Review
아직 bottom-up이 익숙하지 않아서 이해가 잘 안된다. 처음에는 메모이제이션을 짰는데 시간초과가 나서 bottom-up으로 풀어야했다. bottom-up으로도 문제를 풀어봐야겠다.
