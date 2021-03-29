#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int n;
long long cache[101];

int main() {
    cin >> n;
    
    for (int i = 0; i <= 6; i++) {
        cache[i] = i;
    }
    for (int i = 7; i <= n; i++) {
        cache[i] = cache[i - 1] + 1;
        for (int j = 1; j <= i - 3; j++) {
            cache[i] = max(cache[i], cache[j] + cache[j] * (i - (j + 2)));
        }
    }
    cout << cache[n] << '\n';
}
