# [7579] 앱
## 📕 Algorithm
다이나믹 프로그래밍
## 📗 Logic
최소 비용을 찾는 식으로 함수를 구현하면 아래의 코드처럼 구현할 수 있다.
```c++
int minimum_cost(int mem, int pos) {
    if (pos >= n) {
        if (mem < m) return 10000;
        return 0;
    }
    int& ret = cache[mem][pos];
    if (ret != -1) return ret;
    
    int res = 10000;
    if(mem < m) {
        res = min(res, minimum_cost(mem + memory[pos], pos + 1) + cost[pos]);
    }
    res = min(res, minimum_cost(mem, pos + 1));
    ret = res;

    return ret;
}
```
하지만 이렇게 구현을 하면 cache의 크기를 ```int cache[20000000][100]```으로 구현해야해서 메모리 초과가 난다.

### 해결법

따라서, 메모리를 인자로 넘기는 것이 아니라 **비용을 인자로 하고 메모리를 구하는 식**으로 변경해서 풀어야 한다.

구하고자 하는 비용을 tcost로 둔다. tcost를 0부터 최대값인 10000까지 순회하면서 메모리의 합이 확보해야 하는 메모리의 합을 넘는 순간의 tcost가 최소 비용이 된다.
```c++
int calculate(int tcost, int pos) {
    if (pos >= n) return 0;
    int& ret = cache[tcost][pos];
    if (ret != -1) return ret;
    
    int res = calculate(tcost, pos + 1);
    if (tcost >= cost[pos]) res = max(res, calculate(tcost - cost[pos], pos + 1) + memory[pos]);  //메모리를 더 많이 확보하는 것을 선택한다.
    ret = res;
    
    return ret;
}
```
## 📘 Review
처음 아이디어로 빠르게 구현하고 재출했지만 컴파일 에러가 떳다. 메모리 초과가 났다. 

그래서 인자값을 바꿔줘야 한다는 생각을 하긴 했지만, 전혀 정답이 아닐 것 같았기도 했고 그런식으로 구현했을 때 어떻게 구현해야 하는지 생각도 나지않아 거의 포기하고 나처럼 탑-다운으로 푼 사람이 있나 찾아봤다.

찾다보니 딱 한분이 있어서 그 분의 코드를 봤는데 머리를 한대 맞은 것 같았다. 이런 식의 문제를 처음 접해봤다. 너무 어렵다.

이런 식의 문제를 더 찾아서 풀어봐야겠다.
