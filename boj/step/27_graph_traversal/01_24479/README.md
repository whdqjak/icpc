# boj 24479_알고리즘 수업 - 깊이 우선 탐색 1

## 구현방법
vector<int> adj[100001];    //adj[i]: 정점 i와 연결된 정점벡터
int visited[100001];    //방문기록배열

void dfs(int x) {   //x를 방문하고 x와 연결된 정점들을 순차적으로 dfs방문
    visited[x] = ++order;
    for (int nxt : adj[x]) {
        if (visited[nxt] == 0)
            dfs(nxt);
    }
}