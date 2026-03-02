#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

int V, E;
vector<vector<pair<int,int>>> graph;    //{정점, 가중치}
vector<vector<int>> dist;

void floyd(){

    dist.assign(graph.size(), vector<int>(graph.size(), INF));

    //원래는 i,i(자기자신)의 최단거리는 0으로 초기화해줘야 하지만
    //사이클을 구해야 하므로 안함

    for(int i=1;i<=V;++i){
        for(auto u : graph[i]){
            dist[i][u.first] = u.second;
        }
    }

    for(int k = 1;k<=V;++k){
        for(int i=1;i<=V;++i){
            for(int j=1;j<=V;++j){
                if(dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>V>>E;

    graph.assign(V+1, vector<pair<int, int>>());

    int a,b,c;
    while(E--){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }

    floyd();

    int ans=INF;
    for(int i = 1;i<=V;++i){
        ans = min(ans, dist[i][i]);
    }

    if(ans==INF) cout<<-1;
    else cout<<ans;

    return 0;
}