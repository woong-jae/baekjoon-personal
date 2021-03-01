#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int cache[12];

int make_number(int a) {
    if (a == 0) return 1;
    int& ret = cache[a];
    if(ret != -1) return ret;
    
    int res = 0;
    for (int i = 1; i <= 3; i++) {
        if (a - i >= 0) res += make_number(a - i);
    }
    ret = res;
    
    return ret;
}

int main() {
    int t, n;
    vector<int> input;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        input.push_back(n);
    }
    for (int i = 0; i < t; i++) {
        memset(cache, -1, sizeof(cache));
        cout << make_number(input[i]) << '\n';
    }
}

