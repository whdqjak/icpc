# boj 13549_숨바꼭질 3

## 문제
-bfs문제인데 간선의 가중치가 1이 아니라 0도 있음

## 문제 풀이
-나는 dijkstra방식으로 풀었다
근데 bfs로 하는게 훨씬 효율적

-그냥 일반 bfs로 하면 오류가 생김(나중에 방문하면 최단경로가 아니게 되는데 이게 안됨 0때문에)

그래서 가중치가 0인 상황에서는 큐의 앞부분에 넣어줘서 방문순서(레벨?)를 같게 만들어줌!
int bfs(int s, int e){

    vector<int> dist(100001, INF);
    deque<int> dq;

    dist[s] = 0;
    dq.push_front(s);

    while(!dq.empty()){
        int v = dq.front();
        dq.pop_front();

        if(v == e) return dist[v];

        int next[3] = {v-1, v+1, 2*v};
        int cost[3] = {1,1,0};

        for(int i=0;i<3;++i){
            int nx = next[i];
            if(nx<0 || nx>100000) continue;

            if(dist[v] + cost[i] < dist[nx]){
                dist[nx] = dist[v] + cost[i];

                if(cost[i] == 0)
                    dq.push_front(nx);  //이 부분(0 넣어주는 부분)
                else
                    dq.push_back(nx);
            }
        }
    }
    return dist[e];
}