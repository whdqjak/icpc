# 최단 경로

## bfs

## 다익스트라

vector<vector<pair<int,int>>> graph;
vector<int> dijkstra(int s){

    vector<int> dist(graph.size(), INF);
    priority_queue<pair<int,int>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        auto cv = pq.top();
        pq.pop();

        int curDist = -cv.first;
        int cur = cv.second;

        if(curDist > dist[cur]) continue;

        for(auto nxt : graph[cur]){
            int nxtNode = nxt.first;
            int w = nxt.second;

            int nxtDist = curDist+w;

            if(dist[nxtNode] > nxtDist){
                dist[nxtNode] = nxtDist;
                pq.push({-nxtDist, nxtNode});
            }
        }
    }

    return dist;
}

## 벨만 포드

vector<vector<pair<int,int>>> graph;

vector<long long> bellmanFord(int st){

    int V = graph.size() - 1;
    vector<long long> upper(graph.size(), INF);

    upper[st] = 0;

    // V-1번 완화
    for(int i = 1; i <= V-1; ++i){
        for(int j = 1; j <= V; ++j){
            for(auto v : graph[j]){
                if(upper[j] != INF &&
                   upper[v.second] > upper[j] + v.first){
                    upper[v.second] = upper[j] + v.first;
                }
            }
        }
    }

    // 음수 사이클 검사
    for(int j = 1; j <= V; ++j){
        for(auto v : graph[j]){
            if(upper[j] != INF &&
               upper[v.second] > upper[j] + v.first){
                return {};
            }
        }
    }

    return upper;
}

## 플로이드

//초기버전
int V;
int adj[maxV][maxV];
int c[maxV][maxV][maxV];

void floyd_P(){
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            if(i != j){
                c[0][i][j] = min(adj[i][j], adj[i][0]+adj[0][j]);
                
                //i에서j로 가는거,i에서 0으로갔다가 j로 가는거
            }
            else c[0][i][j]=0;
        }
    }

    //경유점을 0에서만 했다면
    //이번엔 모든점을 다 경유점에 포함
    //(경유점이 집합{0~k-1}일 때 최단경로를 안다면 집합{0~k}일때 최단경로를 구할 수 있음)
    //그렇게 k를 늘려가면서 결국엔 모든점을 경유점으로 설정했을 때 최단경로를 구할 수 있음

    for(int k = 1;k<V;++k){
        for(int i=0;i<V;++i){
            for(int j=0;j<V;++j){
                c[k][i][j] = min(c[k-1][i][j], c[k-1][i][k]+adj[k-1][k][j]);
                //i에서j로 가는거,i에서 k으로갔다가 j로 가는거
            }
        }
    }

}


//최종버전
int V;
int adj[maxV][maxV];
int c[maxV][maxV];

void floyd() {
    // adj -> c 복사
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            c[i][j] = adj[i][j];

    // Floyd–Warshall
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (c[i][k] != INF && c[k][j] != INF)
                    c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
}

## 각 방법에 대한 최단 경로의 경로점 구하기