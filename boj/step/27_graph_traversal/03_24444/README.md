# boj 24444_알고리즘 수업 - 너비 우선 탐색 1

## 구현 방법
vector<int> adj[100001];    //adj[i]: 정점 i와 연결된 정점벡터
int visited[100001];    //방문기록배열

void bfs(int x){    //x를 방문하고 방문한 정점과 인접한 정점들을 순차적으로 전부 방문
    int cnt = 0;
    visited[x] = ++cnt;
    
    queue<int> q;
    q.push(x);

    int u;
    while(!q.empty()){
         u = q.front();
         q.pop();
         for(int i: adj[u]){
            if(visited[i]==0){
                visited[i] = ++cnt;
                q.push(i);
            }
         }
    }

}