#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

vector<vector<pair<int,int>>> graph;    // graph[i][j] = i와 인접한 j번째의 {거리, 정점}

vector<int> dijkstra(int s){
    vector<int> dist(graph.size(), INF);
    dist[s] = 0;

    priority_queue<pair<int,int>> pq; //s에서 c까지의 {-거리, c}
    
    pq.push({0,s});
    while(!pq.empty()){
        auto [cD, cV] = pq.top();
        cD*=-1;
        pq.pop();

        if(cD>dist[cV]) continue;

        for(auto [iD, iV] : graph[cV]){
            if(cD+iD<dist[iV]){
                dist[iV] = cD+iD;
                pq.push({-dist[iV], iV});
            }
        }
    }
    
    return dist;
}

void solve(){
    int n,m,t;
    cin>>n>>m>>t;

    graph.assign(n+1,vector<pair<int,int>>());

    int s,g,h;
    cin>>s>>g>>h;

    int a,b,d;
   while(m--){
        cin>>a>>b>>d;
        graph[a].push_back({d,b});
        graph[b].push_back({d,a});
    }

    int x;
    vector<int> distS = dijkstra(s);
    vector<int> distG = dijkstra(g);
    vector<int> distH = dijkstra(h);

    int distS_G_H = distS[g]+distG[h];
    int distS_H_G = distS[h]+distH[g];

    priority_queue<int> ans;
    while(t--){
        cin>>x;
        if(distS_G_H+distH[x]==distS[x] ||
        distS_H_G+distG[x]==distS[x]) ans.push(-x);
    }

    int i;
    while(!ans.empty()){
        i = ans.top();
        ans.pop();
        cout<<-i<<' ';
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    while(T--) solve();
    
    return 0;
}