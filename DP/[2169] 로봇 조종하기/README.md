# [2169] 로봇 조종하기
## 💡Algorithm
- DP
## 📚Logic
현재 위치에서 왼쪽, 아래, 오른쪽으로 이동했을때 중 가장 최대 가치를 선택해서 현재 가치에 더한다.

여기서 메모이제이션을 적용할 때 부모의 위치가 어디냐에 따라 최대 가치가 달라지기 때문에 부모의 위치에 따라 메모이제이션을 적용해야 한다.

또한, 부모의 위치를 통해 어디를 방문했는지 알 수 있어, ```visited```배열을 따로 선언할 필요가 없다.

```c++
int max_investigation(int cr, int cc, int parent) {
    if (cr == n - 1 && cc == m - 1) return map[n - 1][m - 1];
    int &ret = cache[cr][cc][parent];
    if (ret != -1) return ret;
    
    ret = -100000000;
    if(0 <= cr && cr < n && 0 <= cc - 1 && cc - 1 < m && parent != 2 ) ret = max(ret, max_investigation(cr, cc - 1, 0) + map[cr][cc]);
    if(0 <= cr + 1 && cr + 1 < n && 0 <= cc && cc < m) ret = max(ret, max_investigation(cr + 1, cc, 1) + map[cr][cc]);
    if(0 <= cr && cr < n && 0 <= cc + 1 && cc + 1 < m && parent != 0) ret = max(ret, max_investigation(cr, cc + 1, 2) + map[cr][cc]);
    
    return ret;
}
```
## 📝Review
부모의 위치에 따라 메모이제이션을 따로 적용해야한다는 것만 착안한다면 쉽게 풀 수 있는 문제다.
