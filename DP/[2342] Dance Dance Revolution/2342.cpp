#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
int n, cache[100001][5][5];
vector<int> input;

int cal(int a, int b) {
    if (a == 0 || b == 0) return 2;

    int dif = abs(a - b);
    if (dif == 0) return 1;
    else if (dif == 1 || dif == 3) return 3;
    else if (dif == 2) return 4;
    return 0;
}

int min_power(int cur, int left, int right) {
    if (cur >= input.size()) return 0;
    int &ret = cache[cur][left][right];
    if (ret != -1) return ret;
    
    // 왼쪽발을 움직인다.
    ret = min_power(cur + 1, input[cur], right) + cal(left, input[cur]);
    // 오른쪽발을 움직인다.
    ret = min(ret, min_power(cur + 1, left, input[cur]) + cal(right, input[cur]));
    
    return ret;
}

int main() {
    while (1) {
        int in;
        cin >> in;
        if (in == 0) break;
        input.push_back(in);
    }
    memset(cache, -1, sizeof(cache));
    cout << min_power(0, 0, 0) << '\n';
}
