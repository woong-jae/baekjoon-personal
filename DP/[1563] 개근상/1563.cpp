#include <iostream>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;
int n;
int cache[1001][2][3];

int combinations(int cur, int l, int a) {
    if (cur == n) return 1;
    int &ret = cache[cur][l][a];
    if (ret != -1) return ret;
    
    ret = 0;
    
    if (l < 1) ret += combinations(cur + 1, l + 1, 0);
    ret += combinations(cur + 1, l, 0);
    if (a < 2) ret += combinations(cur + 1, l, a + 1);
    ret = ret % 1000000;
    
    return ret;
}

int main() {
    cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << combinations(0, 0, 0) << '\n';
}
