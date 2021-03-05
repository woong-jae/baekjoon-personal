# [5557] 1학년
## 💡Algorithm
다이나믹 프로그래밍
## 📚Logic
현재까지 덧셈과 뺄셈이 진행된 수에서 현재 수를 더할 수 있으면 더하고 뺄 수 있으며 뺀다.

만약 ```sum```이 마지막 수와 같아지면 등식이 이루어졌으므로 1을 반환한다. 이 1이 모두 더해지면 상근이가 만들 수 있는 올바른 등식의 개수를 알 수 있다.
```c++
unsigned long long correct_equation(int cur, int sum) {
    if (cur == n - 1) {
        if (sum == seq[n - 1]) return 1;
        else return 0;
    }
    unsigned long long &ret = cache[cur][sum];
    if (ret != -1) return ret;
    
    unsigned long long res = 0;
    if (sum + seq[cur] <= 20) res += correct_equation(cur + 1, sum + seq[cur]);
    if (sum - seq[cur] >= 0) res += correct_equation(cur + 1, sum - seq[cur]);
    ret = res;
    
    return ret;
}
```
## 📝Review
반례와 자료형 때문에 잠시 해맸다. 좀 더 디테일하게 생각하자. 너무 대충짜고 재출하는 듯,,,
