#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

void bfs(int s, int e){

    vector<int> dist(100001, -1);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if(v == e) break;

        int next[3] = {v-1, v+1, 2*v};

        for(int i=0;i<3;++i){
            int nx = next[i];
            if(nx<0 || nx>100000) continue;

            if(dist[nx]==-1){
                dist[nx] = dist[v] + 1;
                q.push(nx);
            }
        }
    }
    
    // 역추적
    vector<int> ans;

    int c = e;
    
    while(1){
        ans.push_back(c);
        if(c == s) break;

        if(c+1 <= 100000 && dist[c+1] == dist[c]-1){
            c = c + 1;
        } 
        else if(c-1 >= 0 && dist[c-1] == dist[c]-1){
            c = c - 1;
        }
        else if(c%2 == 0 && dist[c/2] == dist[c]-1){
            c = c / 2;
        }
    }
    
    reverse(ans.begin(), ans.end());

    cout << dist[e]<<'\n';
    for(int i:ans) cout<<i<<' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin>>N>>M;

    bfs(N,M);
    
    return 0;
}