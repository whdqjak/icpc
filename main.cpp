#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V,E;
    cin>>V>>E;

    graph.assign(V+1, vector<pair<int,int>>());

    int K;
    cin>>K;

    int u,v,w;
    for(int i=0;i<E;++i){
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }

    vector<int> ans = dijkstra(K);
    for(int i=1;i<=V;++i ){
        if(ans[i]==INF) cout<<"INF\n";
        else cout<<ans[i]<<'\n';
    }

    return 0;
}