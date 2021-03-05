#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int k, cache[500][500];
vector<int> chapter;

int sum(int front, int end) {
    int res = 0;
    for (int i = front; i <= end; i++) {
        res += chapter[i];
    }
    return res;
}

int min_cost(int front, int end) {
    if (front == end) return chapter[end];
    int &ret = cache[front][end];
    if (ret != -1) return ret;
    
    int res = min_cost(front, front) + min_cost(front +1, end);
    for (int i = front + 1; i < end; i++) {
        res = min(res, min_cost(front, i) + min_cost(i + 1, end));
    }
    ret = res + sum(front, end);
    
    return ret;
}

int main() {
    int input, T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> k;
        chapter.clear();
        for (int i = 0; i < k; i++) {
            cin >> input;
            chapter.push_back(input);
        }
        memset(cache, -1, sizeof(cache));
        cout << min_cost(0, k - 1) - sum(0, k - 1) << '\n';
    }
}
