# [2056] 작업
## 💡Algorithm
- DP
- graph
##  📚Logic
**선행 관계가 없는 작업들은 동시 수행 가능**하기 때문에 아래와 같이 생각할 수 있다.

어떤 작업을 최소 시간으로 완료할 수 있는 시간 = 이 작업의 선행되는 작업 중 가장 오래걸리는 작업 + 해당 작업에 걸리는 시간

이것을 코드로 구현하면
```c++
int minimum_time(int cur) {
    visited[cur] = 1;
    if (graph[cur].size() == 0) return task_time[cur];
    int &ret = cache[cur];
    if (ret != -1) return ret;
   
    ret = -1;
    for (int i = 0; i < graph[cur].size(); i++) {
        if (ret == -1) ret = minimum_time(graph[cur][i]);
        ret = max(ret, minimum_time(graph[cur][i]));
    }
    ret += task_time[cur];
    
    return ret;
}
```
## 📝Review
선행 관계가 없는 작업들은 동시 수행 가능하다는 조건을 못봐서 1시간을 해맸다… 문제 자체는 어렵지 않다.
