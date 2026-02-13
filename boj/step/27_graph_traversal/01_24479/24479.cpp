#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int visited[100001];
int order = 0;

void dfs(int x) {
    visited[x] = ++order;
    for (int nxt : adj[x]) {
        if (visited[nxt] == 0)
            dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(R);

    for (int i = 1; i <= N; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}
