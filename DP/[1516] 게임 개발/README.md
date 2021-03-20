# [1516] 게임 개발
## 💡Algorithm
- DP
## 📚Logic
경우의 수는 두가지로 볼 수 있다.
1. 선행되는 건물이 없을 때
    - 현재 건물을 짓는데 필요한 시간을 반환하면 된다.
2. 선행되는 건물이 있을 때
    - 먼저 지어야 하는 건물 중 "가장 오래 걸리는 시간" + "현재 건물을 짓는데 걸리는 시간"이 최소시간이 된다.
```c++
int min_construction_time(int cur) {
    if (building_priority[cur].size() == 0) return building_delay[cur];
    int &ret = cache[cur];
    if (ret != -1) return ret;
    ret = min_construction_time(building_priority[cur][0]);

    for (int i = 1; i < building_priority[cur].size(); i++) {
        ret = max(ret, min_construction_time(building_priority[cur][i]));
    }
    ret += building_delay[cur];
    
    return ret;
}
```
## 📝Review
쉬운 문제였다.
