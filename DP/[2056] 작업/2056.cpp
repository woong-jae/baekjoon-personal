#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int n, cache[10001], visited[10001];
vector<vector<int>> graph;
vector<int> task_time;

int minimum_time(int cur) {
    visited[cur] = 1;
    if (graph[cur].size() == 0) return task_time[cur];
    int &ret = cache[cur];
    if (ret != -1) return ret;
   
    ret = -1;
    for (int i = 0; i < graph[cur].size(); i++) {
        if (ret == -1) ret = minimum_time(graph[cur][i]);
        ret = max(ret, minimum_time(graph[cur][i]));
    }
    ret += task_time[cur];
    
    return ret;
}

int main() {
    int res = 0;
    cin >> n;
    graph.resize(n + 1);
    task_time.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int rep, ipt;
        cin >> task_time[i] >> rep;
        for (int j = 0; j < rep; j++) {
            cin >> ipt;
            graph[i].push_back(ipt);
        }
    }
    memset(cache, -1, sizeof(cache));
    for (int i = n; i > 0; i--) {
        if (visited[i] == 0) res = max(res, minimum_time(i));
    }
    cout << res << '\n';
}
