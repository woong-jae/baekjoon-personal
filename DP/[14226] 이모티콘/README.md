# [14226] 이모티콘
## 💡Algorithm
- DP
## 📚Logic
현재 이모티콘의 길이가 ```ts```라고 하면 할수있는 동작은 3가지가 있다.
1. 복사 (클립보드와 ```ts```가 다를때)
2. 붙여넣기 (클립보득 0이 아닐때)
3. 이모티콘 삭제 (아직 방문하지 않은 ```ts```라면)

이것을 그대로 구현한 후 메모이제이션을 적용하면 아래 코드가 된다.
```c++
int minimum_time(int cur, int clipboard) {
    if (cur >= s) return cur - s;
    int &ret = cache[cur][clipboard];
    if (ret != -1) return ret;
    
    int res = 1000;
    visited[cur] = 1;
    if (cur < s) {
        if (cur != clipboard) res = min(res, minimum_time(cur, cur) + 1);//복사
        if (clipboard) res = min(res, minimum_time(cur + clipboard, clipboard) + 1);
    }
    if (visited[cur - 1] == 0 && cur - 1 > 0) res = min(res, minimum_time(cur - 1, clipboard) + 1);
    ret = res;
    
    return ret;
}
```
## 📝Review
어렵지 않게 푼 문제. 3개의 부분 문제로 각각 들어가는 조건이 중요했다.
