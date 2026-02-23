# boj 1753_최단경로

## 문제
-한 정점으로부터 나머지 정점의 최단경로를 다익스트라 알고리즘을 통해서 구하는 문제

## 다익스트라 구현
-알고리즘 내용은 기준 정점으로부터 인접한 정점 중 가장 거리가 가까운 정점부터 방문하면서
모든 정점의 최단거리를 구하는 방식.(가중치에 음수가 있으면 못쓴다!)
(쉽게 설명해서 a에서 b까지의 최단거리를 구하기 위해서 a에서 중간까지의 최단거리를 구한 후 중간에서 목적지까지의 최단거리를 구하는 느낌?)
(근데 그 중간이라는 정점이 되게 여러개 있으므로 구한 최단거리중 최솟값을 구하면 됨)

-아래 구현은 bfs랑 비슷함
다른점은 우선순위 큐를 사용했고 방문한 곳을 재방문할 수 있다(그래서 재방문 했을 때 이게 최단거리가 아니면 그냥 무시함)

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

-우선순위 큐를 사용하지 않은 구현도 있음
아래 방식은 우선순위 큐를 사용하지 않은 대신 방문하지 않은
정점들 중에서 가장 거리가 짧은 정점을 직접 찾아서 방문하는 방식
vector<int> dijkstra(int s){

    int V = graph.size();
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    dist[s] = 0;

    for(int i = 0; i < V; ++i){

        int cur = -1;

        for(int j = 0; j < V; ++j){
            if(!visited[j] && dist[j] < dist[cur]){
                cur = j;
            }
        }

        if(cur == -1) break;

        visited[cur] = true;

        for(auto nxt : graph[cur]){
            int nxtNode = nxt.first;
            int w = nxt.second;

            if(dist[nxtNode] > dist[cur] + w){
                dist[nxtNode] = dist[cur] + w;
            }
        }
    }

    return dist;
}

## 다시 상기시킬만한것들
-pair는 첫번째 원소 기준으로 정렬된다.
-vector<int>() 이렇게 쓰면 객체표현임(초기화 할 때나 함수 인자로 쓸 수 있음)
-함수 인자 참조로 하는건 왠만해선 좋다(잘 쓰면 단점이 없고 오히려 좋기만 함)
(값 수정위험이 걱정되면 const 쓰기)
(큰 데이터를 넘길 때 좋다,int같은 작은 데이터는 그냥 쓰는게 더 나음)