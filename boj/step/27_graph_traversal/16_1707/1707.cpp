#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> color;

bool bfs(int start){
    queue<int> q;
    q.push(start);
    color[start] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int nxt : graph[cur]){
            if(color[nxt] == -1){
                color[nxt] = color[cur] ^ 1;
                q.push(nxt);
            }
            else if(color[nxt] == color[cur]){
                return 0;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;

    while(K--){
        int V, E;
        cin >> V >> E;

        graph.assign(V + 1, vector<int>());
        color.assign(V + 1, -1);

        for(int i = 0; i < E; ++i){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        bool ans = 1;

        for(int i = 1; i <= V; ++i){
            if(color[i] == -1){
                if(!bfs(i)){
                    ans = 0;
                    break;
                }
            }
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}