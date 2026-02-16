#include <bits/stdc++.h>
using namespace std;

int N,M;

vector<int> adj[32001];
int deg[32001];

vector<int> topoSort(){

    queue<int> indeg;

    for(int i=1;i<=N;++i){
        for(int nxt : adj[i]){
            ++deg[nxt];
        }
    }
    for(int i=1;i<=N;++i)
        if(deg[i]==0) indeg.push(i);

    vector<int> result;
    int cur;
    while(!indeg.empty()){
        cur = indeg.front();
        indeg.pop();
        result.push_back(cur);

        for(int nxt : adj[cur]){
            --deg[nxt];
            if(deg[nxt]==0) indeg.push(nxt);
        }
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;

    int a,b;
    while(M--){
        cin>>a>>b;
        adj[a].push_back(b);
    }

    vector<int> ans = topoSort();
    for(int i : ans) cout<<i<<' ';

    return 0;
}