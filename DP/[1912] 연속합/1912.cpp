#include <iostream>

using namespace std;
int n, sequence[100000], dp[100000];

int main() {
    int max_val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    dp[0] = sequence[0];
    max_val = dp[0];
    for (int i = 1; i < n; i++) {
        if (sequence[i] + dp[i - 1] > sequence[i]) dp[i] = sequence[i] + dp[i - 1];
        else dp[i] = sequence[i];
        max_val = max(max_val, dp[i]);
    }
    cout << max_val << '\n';
}
