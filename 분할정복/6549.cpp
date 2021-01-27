#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<long long> h;

long long max_rectangle(int left, int right) {
    if(left == right) return h[left];//기저사례
    int mid = (left + right) / 2;
    //왼쪽 오른쪽 분할
    long long ret = max(max_rectangle(left, mid), max_rectangle(mid + 1 , right));
    //겹치는 부분 처리
    int left_pivot = mid, right_pivot = mid + 1;
    long long height = min(h[left_pivot], h[right_pivot]);
    ret = max(ret , height * 2);
    while(left < left_pivot || right_pivot < right) {
        if (right_pivot < right && (left_pivot == left || h[left_pivot - 1] < h[right_pivot + 1])) {
            right_pivot++;
            height = min(height, h[right_pivot]);
        } else {
            left_pivot--;
            height = min(height, h[left_pivot]);
        }
        ret = max(ret, (right_pivot - left_pivot + 1) * height);
    }
    return ret;
}

int main() {
    int n, input;
    
    while(1) {
        cin >> n;
        if(n == 0) break;
        
        for(int i = 0; i < n; i++) {
            cin >> input;
            h.push_back(input);
        }
        cout << max_rectangle(0, n - 1) << '\n';
        h.clear();
    }
}
