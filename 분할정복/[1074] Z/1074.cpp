#include <iostream>
#include <cmath>

using namespace std;
int n, r, c;
int cnt = 0;

void travel(int tr, int tc, int n) {
    if (n == 0) {
        if (tr == r && tc == c) {
            cout << cnt << '\n';
        }
    } else {
        int size = (pow(2, n) * pow(2, n)) / 4;
        if (tr + pow(2, n - 1) > r) {
            if (tc + pow(2, n - 1) > c) {
                travel(tr, tc, n - 1);
            } else {
                cnt = cnt + size;
                travel(tr, tc + pow(2, n - 1), n - 1);
            }
        } else {
            if (tc + pow(2, n - 1) > c) {
                cnt = cnt + 2 * size;
                travel(tr + pow(2, n - 1), tc, n - 1);
            } else {
                cnt = cnt + 3 * size;
                travel(tr + pow(2, n - 1), tc + pow(2, n - 1), n - 1);
            }
        }
    }
}

int main() {
    cin >> n >> r >> c;
    travel(0, 0, n);
}
