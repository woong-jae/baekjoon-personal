#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, m;
int map[1000][1000], visited[1000][1000], cache[1000][1000][3];
int dr[3] = {0, 1, 0};
int dc[3] = {-1, 0, 1};

int max_investigation(int cr, int cc, int parent) {
    if (cr == n - 1 && cc == m - 1) return map[n - 1][m - 1];
    int &ret = cache[cr][cc][parent];
    if (ret != -1) return ret;
    
    ret = -100000000;
    visited[cr][cc] = 1;
    for (int i = 0; i < 3; i++) {
        int tr = cr + dr[i], tc = cc + dc[i];
        if(0 <= tr && tr < n && 0 <= tc && tc < m && visited[tr][tc] == 0) {
            ret = max(ret, max_investigation(tr, tc, i) + map[cr][cc]);
        }
    }
    visited[cr][cc] = 0;
    
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    cout << max_investigation(0, 0, 0) << '\n';
}
