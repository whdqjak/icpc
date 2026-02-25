#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

int dijkstra(int s, int e){
    
    vector<int> dist(100001, INF);

    dist[s] = 0;

    priority_queue<pair<int,int>> pq;   //{-거리, 정점}
    pq.push({0,s});

    int cost[3] = {1,1,0};

    int ux;
    while(!pq.empty()){
        auto [w,x] = pq.top();
        w*=-1;
        pq.pop();

        if(w>dist[x]) continue;
        if(x==e) return w;

        int dx[3] = {x-1,x+1,2*x};
        for(int i=0;i<3;++i){
            ux = dx[i];
            if(0<=ux && ux<=100000 && w+cost[i]<dist[ux]){
                dist[ux] = w+cost[i];
                pq.push({-dist[ux], ux});
            }
        }
    }
    
    return dist[e];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin>>N>>M;

    cout<<dijkstra(N,M);

    return 0;
}