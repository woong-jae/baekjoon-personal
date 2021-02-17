# [1915] 가장 큰 정사각형
## 💡Algorithm

다이나믹 프로그래밍

## 💡Logic

배열을 순회하면서 현재 위치의 숫자가 '1'이면 만들 수 있는 최대 정사각형의 크기를 구한다.

### 최대 정사각형 크기 구하기

현재 위치에서 좌대각 하단, 왼쪽, 하단의 최대 정사각형 크기 중 가장 작은 값을 현재 값(1)에 더하면 최대 크기가 된다.

1. 좌대각 하단, 왼쪽, 하단을 검사한다.
    - 좌대각 하단부터 들어가야 한다!
2. 가장 작은 값을 현재 크기(1)에 더한다.

기저사례는 배열의 범위를 벗어나거나 현재 위치의 숫자가 '0'일 때이다.

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

가장 큰 정사각형을 어떻게 구할지 생각하는데 좀 걸린 것 빼고는 크게 어렵지는 않았다. 

이런 기본 유형을 더 빨리 풀 수 있게 연습해야겠다.
