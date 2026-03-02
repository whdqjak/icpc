#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

int N, M;
vector<vector<int>> dist;

void floyd() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    dist.assign(N + 1, vector<int>(N + 1, INF));

    // 자기 자신 0
    for (int i = 1; i <= N; ++i)
        dist[i][i] = 0;

    // 간선 입력 (중복 최소 처리)
    int a, b, c;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    floyd();

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (dist[i][j] == INF) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}