#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int dr[4] = {0, -1, 0, 1};//오른쪽부터 반시계방향
int dc[4] = {1, 0, -1, 0};
vector<string> building(1000);

int escape(int w, int h) {
    int res = 0;
    queue<pair<int, int>> fire;
    queue<pair<int, int>> movement;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (building[i][j] == '*') fire.push(make_pair(i, j));
            if (building[i][j] == '@') movement.push(make_pair(i, j));
        }
    }
    while (1) {
        int fire_size = (int)fire.size();
        for (int i = 0; i < fire_size; i++) {
            for (int j = 0; j < 4; j++) {
                int nr = fire.front().first + dr[j], nc = fire.front().second + dc[j];
                if (0 <= nr && nr < h && 0 <= nc && nc < w && building[nr][nc] != '#' && building[nr][nc] != '*') {
                    building[nr][nc] = '*';
                    fire.push(make_pair(nr, nc));
                }
            }
            fire.pop();
        }
        int mv_size = (int)movement.size();
        for (int i = 0; i < mv_size; i++) {
            int cr = movement.front().first, cc = movement.front().second;
            if (0 == cr || cr == h - 1 || 0 == cc || cc == w - 1) return res + 1; //escaped!
            for (int j = 0; j < 4; j++) {
                int nr = cr + dr[j], nc = cc + dc[j];
                if (0 <= nr && nr < h && 0 <= nc && nc < w && building[nr][nc] == '.') {
                    building[nr][nc] = '@';
                    movement.push(make_pair(nr, nc));
                }
            }
            movement.pop();
        }
        if (movement.size() == 0) return 0;
        res++;
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int w, h, res;
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            cin >> building[i];
        }
        res = escape(w, h);
        if (res) cout << res << '\n';
        else cout << "IMPOSSIBLE" << '\n';
    }
}
