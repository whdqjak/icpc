#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

int N,E;
vector<vector<pair<int,int>>> graph; //{거리, 정점}

vector<int> dijkstraF(int st){
    vector<int> dist(graph.size(), INF);
    dist[st] = 0;

    priority_queue<pair<int,int>> pq;   //{-거리, 정점}
    pq.push({0,st});
    while(!pq.empty()){
        auto v = pq.top();
        pq.pop();

        if(-v.first > dist[v.second]) continue;
        for(auto nxt : graph[v.second]){
            if(nxt.first-v.first<dist[nxt.second]){
                dist[nxt.second] = nxt.first-v.first;
                pq.push({-dist[nxt.second], nxt.second});
            }
        }

    }

    return dist;
}

int dijkstraF2(int a, int b){
    vector<int> dist1 = dijkstraF(1);
    if(dist1[a]==INF || dist1[b]==INF) return -1;
    vector<int> distN = dijkstraF(N);
    if(distN[a]==INF || distN[b]==INF) return -1;
    vector<int> distA = dijkstraF(a);
    if(distA[b]==INF) return -1;

    int m1 = dist1[a]+distN[b]+distA[b]; //a에서 b로
    int m2 = dist1[b]+distN[a]+distA[b]; //b에서 a로

    return m1<m2?m1:m2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>E;
    
    graph.assign(N+1, vector<pair<int,int>>());
    
    int u,v,c;
    for(int i=0;i<E;++i){
        cin>>v>>u>>c;
        graph[v].push_back({c,u});
        graph[u].push_back({c,v});
    }

    int a,b;
    cin>>a>>b;

    cout<<dijkstraF2(a,b);

    return 0;
}