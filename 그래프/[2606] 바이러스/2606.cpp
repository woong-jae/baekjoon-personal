#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int computer, connection;
int graph[101][101], visited[101] = {0, };

int spread_virus() {
    int res = 0;
    queue<int> q;
    visited[1] = 1;
    q.push(1);
    while(q.size()) {
        for (int i = 1; i <= computer; i++) {
            if (graph[q.front()][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
                res++;
            }
        }
        q.pop();
    }
    
    return res;
}

int main() {
    int r, c;
    cin >> computer >> connection;
    for (int i = 0; i < connection; i++) {
        cin >> r >> c;
        graph[r][c] = 1;
        graph[c][r] = 1;
    }
    cout << spread_virus() << '\n';
}

