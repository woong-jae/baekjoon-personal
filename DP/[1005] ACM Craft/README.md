# [1005] ACM Craft
## 💡Algorithm

다이나믹 프로그래밍

## 💡Logic

건설해야 하는 건물 W부터 역으로 추적해서 건설시간을 찾는다. 지금 건물에서부터 갈 수 있는 다른 건물들 중 가장 오래걸리는 것을 선택한다.
```c++
int track_time(int col) {
    int& ret = cache[col];
    if(ret != -1) return ret;
    
    int res = construct_time[col];
    for(int i = 0; i < n; i++) {
        if(graph[i][col]) {//건물 탐색
            res = max(res , construct_time[col] + track_time(i));
        }
    }
    ret = res;
    
    return ret;
}
```

## 💡Review

재귀함수를 짜는대는 별로 오래걸리지 않았다. 다 해놓고 DP를 어떻게 적용시킬지 고민하고 있었다.

중복계산이 일어나는 부분이 직관적으로 보이지 않아서였던 것 같다. 보통 캐쉬는 재귀함수의 인자 수와 똑같은 것 같다. 어렵게 생각하지 말자.
