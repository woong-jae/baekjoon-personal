#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int memory[100], cost[100];
int cache[10000][100];

int calculate(int tcost, int pos) {
    if (pos >= n) return 0;
    int& ret = cache[tcost][pos];
    if (ret != -1) return ret;
    
    int res = calculate(tcost, pos + 1);
    if (tcost >= cost[pos]) res = max(res, calculate(tcost - cost[pos], pos + 1) + memory[pos]);
    ret = res;
    
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> memory[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < 10000; i++) {
        int mem = calculate(i, 0);
        if (mem >= m) {
            cout << i << '\n';
            break;
        }
    }
}
