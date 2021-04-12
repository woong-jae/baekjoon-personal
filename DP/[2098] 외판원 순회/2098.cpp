#include <iostream>
#include <vector>
#include <cstring>
#define MAX 16
#define INF 1e9

using namespace std;
int n, w[MAX][MAX];
int cache[MAX][1<<MAX];

int shortestPath(int here, int visited) {
    if (visited == (1<<n) - 1) return w[here][0];
    int &ret = cache[here][visited];
    if (ret != -1) return ret;
    ret = INF;
    for (int next = 0; next < n; next++) {
        if (visited & (1<<next)) continue;
        int cand = w[here][next] + shortestPath(next, visited + (1<<next));
        ret = min(ret, cand);
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
            if (w[i][j] == 0) w[i][j] = INF;
        }
    }
    memset(cache, -1, sizeof(cache));
    int res = shortestPath(0, 1);
    cout << res << '\n';
}
