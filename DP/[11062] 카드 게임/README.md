# [11062] 카드 게임
## 💡Algorithm
- DP
## 📚Logic
근우와 명우과 최선을 다했을 때 근우가 얻게되는 점수를 구해야한다.

근우의 부분문제는 두가지 뿐이다.
1. 왼쪽을 골랐을 때
2. 오른쪽을 골랐을 때

고른 후 명우가 최선의 선택을 했을 때를 처리해주면 된다.
```c++
int guens_pick(int start, int end) {//근우의 최선의 선택
    if (start > end) return 0;
    int &ret = cache[start][end];
    if (ret != -1) return ret;
    
    //왼쪽
    ret = myeongs_pick(start + 1, end) + card[start];
    //오른쪽
    ret = max(ret, myeongs_pick(start, end - 1) + card[end]);
    
    return ret;
}
```

명우가 최선의 선택을 했다는 것은 반대로 근우의 점수가 최소가 될 때이다. 명우의 부분문제도 근우의 부분 문제와 같지만, 근우의 점수가 최소가 되야 하므로 선택할 때 더 작은것을 고르면 된다.
```c++
int myeongs_pick(int start, int end) {//명우의 최선의 선택
    if (start > end) return 0;
    int &ret = cache[start][end];
    if (ret != -1) return ret;

    ret = guens_pick(start + 1, end);
    ret = min(ret, guens_pick(start, end - 1));

    return ret;
}
```
