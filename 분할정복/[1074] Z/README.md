# [1074] Z
## 📕 Algorithm
분할 정복
## 📗 Logic
완전 탐색을 할 수도 있지만, 비효율적이다. 왜냐하면 현재 배열을 사분면으로 나누었을 때, 원하는 r과 c가 어느 사분면에 있는지 알 수 있기 때문이다.

따라서 모두 들어가는 것이 아니라 검사를 한 후 바로 찾아서 들어가는 것이다. 들어가지 않은 탐색의 수만큼은 ```cnt```에 더해주면 된다.

```c++
void travel(int tr, int tc, int n) {
    if (n == 0) {
        if (tr == r && tc == c) {
            cout << cnt << '\n';
        }
    } else {
        int size = (pow(2, n) * pow(2, n)) / 4;
        if (tr + pow(2, n - 1) > r) {
            if (tc + pow(2, n - 1) > c) { //1
                travel(tr, tc, n - 1);
            } else { //2
                cnt = cnt + size;
                travel(tr, tc + pow(2, n - 1), n - 1);
            }
        } else {
            if (tc + pow(2, n - 1) > c) { //3
                cnt = cnt + 2 * size;
                travel(tr + pow(2, n - 1), tc, n - 1);
            } else { // 4
                cnt = cnt + 3 * size;
                travel(tr + pow(2, n - 1), tc + pow(2, n - 1), n - 1);
            }
        }
    }
}
```
## 📘 Review
처음에 시간제한이 0.5초인지 모르고 완전탐색으로 풀었다가 시간초과가 났다. 문제를 다 읽고 풀자 ㅎㅎ;
