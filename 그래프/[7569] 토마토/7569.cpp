#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef struct {
    int r, c, h;
}pos;

int n, m, h;
int box[100][100][100];
int dh[2] = {-1, 1};
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
queue<pos> q;

int check() {
    int res = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if (box[i][j][k] == 0) {
                    return -1;
                }
                res = max(res, box[i][j][k]);
            }
        }
    }
    return res - 1;
}

void affect() {
    while (q.size()) {
        pos cur = q.front(), temp;
        temp = cur;
        
        int day = box[cur.h][cur.r][cur.c];
        for (int i = 0; i < 2; i++) {
            if (0 <= cur.h + dh[i] && cur.h + dh[i] < h && box[cur.h + dh[i]][cur.r][cur.c] == 0) {
                box[cur.h + dh[i]][cur.r][cur.c] = day + 1;
                temp.h = cur.h + dh[i];
                q.push(temp);
            }
        }
        temp.h = cur.h;
        for (int i = 0; i < 4; i++) {
            if (0 <= cur.r + dr[i] && cur.r + dr[i] < n && 0 <= cur.c + dc[i] && cur.c + dc[i] < m && box[cur.h][cur.r + dr[i]][cur.c + dc[i]] == 0) {
                box[cur.h][cur.r + dr[i]][cur.c + dc[i]] = day + 1;
                temp.r = cur.r + dr[i]; temp.c = cur.c + dc[i];
                q.push(temp);
            }
        }
        q.pop();
    }
}


int main() {
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) {
                    pos cur;
                    cur.h = i; cur.r = j; cur.c = k;
                    q.push(cur);
                }
            }
        }
    }
    affect();
    cout << check() << '\n';
}
