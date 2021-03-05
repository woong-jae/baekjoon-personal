# [11066] 파일 합치기
## 💡Algorithm
다이나믹 프로그래밍
## 📚Logic
- 부분문제 나누기

하나의 파일은 다른 두 파일의 합으로 이루어진다. 그 중 최소가 되는 파일의 합을 선택하면 된다.

즉 현재 파일은 ```min_cost(front, i) + min_cost(i + 1, end)```(front < i < end) 중 최소가 되는 것이다.
```c++
int min_cost(int front, int end) {
    if (front == end) return chapter[end];
    int &ret = cache[front][end];
    if (ret != -1) return ret;
    
    int res = min_cost(front, front) + min_cost(front +1, end);
    for (int i = front + 1; i < end; i++) {
        res = min(res, min_cost(front, i) + min_cost(i + 1, end));
    }
    ret = res + sum(front, end);
    
    return ret;
}
```
## 📝Review
일단 인접한 파일들만 겹칠 수 있는지 몰랐다. 그래서 아이디어가 도저히 생각이 안나 백준에 있는 질문을 살짝 봤는데, 인접한 파일만 겹칠 수 있었다. 왜 문제에 이런거 안써놨는지...

이걸 알고나서는 쉽게 구현했는데, 누적을 구하는 것에서 많이 해맸다. 어려운 문제였다. 나중에 다시 풀어보자잇~
