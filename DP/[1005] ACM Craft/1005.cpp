#include <iostream>
#include <cstring>

using namespace std;
int n, k, w;
int cache[1000], graph[1000][1000];
int construct_time[1000];

int track_time(int col) {
    int& ret = cache[col];
    if(ret != -1) return ret;
    
    int res = construct_time[col];
    for(int i = 0; i < n; i++) {
        if(graph[i][col]) {
            res = max(res , construct_time[col] + track_time(i));
        }
    }
    ret = res;
    
    return ret;
}

int main() {
    int T;
    cin >> T;
    for(int testcase = 0; testcase < T; testcase++) {
        int r, c;
        cin >> n >> k;
        memset(cache, -1, sizeof(cache));
        memset(graph, 0, sizeof(graph));
        for(int i = 0; i < n; i++) {
            cin >> construct_time[i];
        }
        for(int i = 0; i < k; i++) {
            cin >> r >> c;
            graph[r - 1][c - 1] = 1;
        }
        cin >> w;
        cout << track_time(w - 1) << '\n';
    }
}
