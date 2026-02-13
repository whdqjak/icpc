#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int visited[100001];

int cnt;

void dfs(int x){
    visited[x] = ++cnt;
    for(int i : adj[x]){
        if(visited[i]==0) dfs(i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,R;
    cin>>N>>M>>R;

    int a,b;

    for(int i=1;i<=M;++i){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=N;++i) sort(adj[i].begin(), adj[i].end(), [](const int& a, const int& b){ return a>b;});
    dfs(R);

    for(int i=1;i<=N;++i) cout<<visited[i]<<'\n';

    return 0;
}