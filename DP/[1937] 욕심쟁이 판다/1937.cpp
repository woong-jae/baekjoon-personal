#include <iostream>
#include <cstring>
#include <utility>

using namespace std;
int n;
int bamboo[500][500], cache[500][500];
int y[4] = {1, 0 , -1, 0};
int x[4] = {0, 1, 0, -1};

int dayToLive(int r, int c) {
    int& ret = cache[r][c];
    if(ret != -1) return ret;
    
    int res = 1;
    
    for (int i = 0; i < 4; i++) {
        if(0 <= r + y[i] && r + y[i] < n && 0 <= c + x[i] && c + x[i] < n && bamboo[r][c] < bamboo[r + y[i]][c + x[i]]) {
            res = max(res, dayToLive(r + y[i], c + x[i]) + 1);
        }
    }
    ret = res;
    
    return ret;
}

int main() {
    int res = 1;
    cin >> n ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> bamboo[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, dayToLive(i, j));
        }
    }
    cout << res << '\n';
}
