#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int n, cache[1000][1000];
vector<int> card;

int myeongs_pick(int, int);
int guens_pick(int, int);
int main() {
    int t;
    cin >> t;
    vector<int> ans;
    for (int T = 0; T < t; T++) {
        cin >> n;
        card.clear();
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            card.push_back(temp);
        }
        memset(cache, -1, sizeof(cache));
        ans.push_back(guens_pick(0, (int)card.size() - 1));
    }
    for (int answer : ans) {
        cout << answer << '\n';
    }
}

int myeongs_pick(int start, int end) {//명우의 최선의 선택
    if (start > end) return 0;
    int &ret = cache[start][end];
    if (ret != -1) return ret;

    ret = guens_pick(start + 1, end);
    ret = min(ret, guens_pick(start, end - 1));

    return ret;
}

int guens_pick(int start, int end) {//근우의 최선의 선택
    if (start > end) return 0;
    int &ret = cache[start][end];
    if (ret != -1) return ret;
    
    //왼쪽
    ret = myeongs_pick(start + 1, end) + card[start];
    //오른쪽
    ret = max(ret, myeongs_pick(start, end - 1) + card[end]);
    
    return ret;
}
