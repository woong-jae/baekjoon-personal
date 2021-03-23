#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int t;
long long cache[31][31];

long long all_case(int full, int half) {
    if (full == 0 && half == 0) return 1;
    long long &ret = cache[full][half];
    if (ret != -1) return ret;
    
    ret = 0;
    if (full > 0) ret += all_case(full - 1, half + 1);
    if (half > 0) ret += all_case(full, half - 1);
    
    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    while(1) {
        cin >> t;
        if (t == 0) break;
        cout << all_case(t, 0) << '\n';
    }
}


