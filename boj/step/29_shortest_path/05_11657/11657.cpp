#include <bits/stdc++.h>
#define INF (long long)4e18
using namespace std;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin>>N>>M;

    graph.assign(N+1, vector<pair<int,int>>());

    int a,b,c;
    while(M--){
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
    }

    vector<long long> dist = bellmanFord(1);

    if(dist.empty()){
        cout<<-1;
    }
    else{
        for(int i=2;i<=N;++i){
            if(dist[i]==INF) cout<<-1<<'\n';
            else cout<<dist[i]<<'\n';
        }
    }

    return 0;
}