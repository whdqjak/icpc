#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);
    vector<int> indeg(N + 1, 0);

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        graph[a].push_back(b);
        ++indeg[b];
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= N; ++i) {
        if (indeg[i] == 0)
            pq.push(i);
    }

    int u;
    while (!pq.empty()) {
        u = pq.top();
        pq.pop();

        cout << u << ' ';

        for (int v : graph[u]) {
            --indeg[v];
            if (indeg[v] == 0)
                pq.push(v);
        }
    }

    return 0;
}