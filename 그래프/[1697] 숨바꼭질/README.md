# [1697] 숨바꼭질
## 💡Algorithm
BFS
## 📚Logic
n보다 k가 클때 n + 1 과 n * 2를 방문한다. n - 1 이 0보다 크면 n - 1에 방문한다.

n이 k와 같아질 때까지 반복한다.

```c++
int find_sister(int n, int k) {
    int res = 0;
    int visited[100001] = {0, };
    
    q.push(n);
    visited[n] = 1;
    while (1) {
        int q_size = (int)q.size();
        for (int i = 0; i < q_size; i++) {
            if (q.front() == k) return res;
            if (q.front() < k) {
                if(q.front() + 1 <= 100000 && visited[q.front() + 1] == 0) {
                    q.push(q.front() + 1);
                    visited[q.front() + 1] = 1;
                }
                if(q.front() * 2 <= 100000 && visited[q.front() * 2] == 0) {
                    q.push(q.front() * 2);
                    visited[q.front() * 2] = 1;
                }
       `     }
            if (q.front() - 1 >= 0 && visited[q.front() - 1] == 0) {
                q.push(q.front() - 1);
                visited[q.front() - 1] = 1;
            }
            q.pop();
        }
        res++;
    }
    
    
    return res;
}
```
