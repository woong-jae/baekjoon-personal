#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_V 100
#define INF 987654321

using namespace std;

//정점의 개수
int V;
// 그래프의 인접 행렬 표현.
// adj[u][v] = u에서 v로 가는 간선의 가중치. 간선이 없으면 아주 큰 값을 넣는다.
int adj[MAX_V][MAX_V];
// 플로이드의 모든 쌍 최단 거리 알고리즘
void floyd() {
    //C[0]을 초기화
    for (int i = 0; i < V; i++) adj[i][i] = 0;
    // C[k-1]이 있으면 C[k]를 계산할 수 있다.
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

int main() {
    int m;
    cin >> V >> m;
    fill(&adj[0][0], &adj[MAX_V - 1][MAX_V - 1], INF);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1][b - 1] = min(adj[a - 1][b - 1], c);
    }
    floyd();
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] >= INF) {
                adj[i][j] = 0;
            }
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
}
