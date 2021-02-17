# [1915] 가장 큰 정사각형
## 💡Algorithm

다이나믹 프로그래밍

## 💡Logic

배열을 순회하면서 '1'이면 만들 수 있는 최대 정사각형의 크기를 구한다.

```c++
int maxSqare(pair<int, int> position) {
    if(position.first >= n || position.second >= m || input[position.first][position.second] == '0') return 0;
    int& ret = cache[position.first][position.second];
    if(ret != -1) return ret;
    
    int size = 1000;
    for(int i = 0; i < 3; i++) {
        size = min(size, maxSqare(pair<int, int> (position.first + r[i], position.second + c[i])));
    }
    ret = size + 1;
    
    return ret;
}
```

## 💡Review


