#include <iostream>
#include <cstring>

using namespace std;
int n, k, coin[100];
int dp[10001];

int main() {
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= coin[i]) dp[j] += dp[j - coin[i]];
        }
    }
    
    cout << dp[k] << '\n';
}
