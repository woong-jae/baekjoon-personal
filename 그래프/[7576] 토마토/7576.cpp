#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n, m;
int box[1000][1000];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;

int check() {
    int res = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (box[i][j] == 0) {
                return -1;
            }
            res = max(res, box[i][j]);
        }
    }
    return res - 1;
}

void affect() {
    while (q.size()) {
        int day = box[q.front().first][q.front().second];
        for (int i = 0; i < 4; i++) {
            if (0 <= q.front().first + dr[i] && q.front().first + dr[i] < n && 0 <= q.front().second + dc[i] && q.front().second + dc[i] < m && box[q.front().first + dr[i]][q.front().second + dc[i]] == 0) {
                box[q.front().first + dr[i]][q.front().second + dc[i]] = day + 1;
                q.push(pair<int, int> (q.front().first + dr[i], q.front().second + dc[i]));
            }
        }
        q.pop();
    }
}


int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                q.push(pair<int, int> (i, j));
            }
        }
    }
    affect();
    cout << check() << '\n';
}

