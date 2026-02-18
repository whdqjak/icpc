#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n, vector<vector<bool>>& adj, vector<int> indegree) {

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> result;

    for (int i = 0; i < n; ++i) {

        if (q.empty())
            return vector<int>();

        if (q.size() > 1)
            return vector<int>(1, -1);

        int cur = q.front();
        q.pop();
        result.push_back(cur);

        for (int nxt = 1; nxt <= n; ++nxt) {
            if (adj[cur][nxt]) {
                --indegree[nxt];
                if (indegree[nxt] == 0)
                    q.push(nxt);
            }
        }
    }

    return result;
}

void solve() {
    int n;
    cin >> n;

    vector<int> last(n);
    for (int i = 0; i < n; ++i)
        cin >> last[i];

    vector<vector<bool>> adj(n + 1, vector<bool>(n + 1, 0));
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            adj[last[i]][last[j]] = 1;
            ++indegree[last[j]];
        }
    }

    int m;
    cin >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;

        if (adj[a][b]) {
            adj[a][b] = 0;
            adj[b][a] = 1;
            --indegree[b];
            ++indegree[a];
        } else {
            adj[b][a] = 0;
            adj[a][b] = 1;
            --indegree[a];
            ++indegree[b];
        }
    }

    vector<int> result = topoSort(n, adj, indegree);

    if (result.empty()) {
        cout << "IMPOSSIBLE\n";
    }
    else if (result.size() == 1 && result[0] == -1) {
        cout << "?\n";
    }
    else {
        for (int x : result)
            cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
