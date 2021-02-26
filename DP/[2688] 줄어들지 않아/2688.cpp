#include <iostream>
#include <cstring>

using namespace std;
long long cache[65][10];

long long non_decreasing_number(int length, int cur) {
    if (length == 0) return 1;
    long long& ret = cache[length][cur];
    if (ret != -1) return ret;
    
    long long res = 0;
    for (int i = 0; i < 10; i++) {
        if (i >= cur) res += non_decreasing_number(length - 1, i);
    }
    ret = res;
    
    return ret;
}

int main() {
    int T, input[1000];
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> input[i];
    }
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < T; i++) {
        cout << non_decreasing_number(input[i], 0) << '\n';
    }
}
