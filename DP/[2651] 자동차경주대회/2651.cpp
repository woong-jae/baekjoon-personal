#include <iostream>
#include <vector>

using namespace std;
long long T[102], t[102];
int p[102];

int main() {
    int max_reach, n;
    cin >> max_reach >> n;
    vector<long long> dist(n + 2);
    dist[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        cin >> dist[i];
        dist[i] += dist[i - 1];
        T[i] = 1ll << 40;
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    
    T[0] = 0; p[0] = -1;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j < i; j++) {
            if (dist[i] - dist[j] <= max_reach && (T[i] > T[j] + t[i])) {
                T[i] = T[j] + t[i];
                p[i] = j;
            }
        }
    }
    vector<int> path; int cur = n + 1;
    while (1) {
        int next = p[cur];
        if (next == 0) break;
        path.push_back(next);
        cur = next;
    }
    
    cout << T[n + 1] << '\n' << path.size() << '\n';
    if (path.size()) {
        for (int i = (int)path.size() - 1; i >= 0; i--) {
            cout << path[i] << ' ';
        }
    }
}
