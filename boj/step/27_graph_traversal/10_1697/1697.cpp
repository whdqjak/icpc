#include <bits/stdc++.h>
using namespace std;

int N,K;
bool visited[100001];

int bfs(int x){

    if(x==K) return 0;

    visited[x] = 1;
    queue<pair<int,int>> nxt;
    nxt.push({0, x});
    
    pair<int, int> u;
    int ux;
    while(!nxt.empty()){
        u = nxt.front();
        nxt.pop();

        ux = u.second;

        int dx_f[3] = {ux-1,ux+1,2*ux};
        for(int i=0, ix;i<3;++i){
           ix = dx_f[i];
           if(ix == K) return u.first+1;
           if(0<=ix && ix<=(int)1e5 && !visited[ix]){
                visited[ix] = 1;
                nxt.push({u.first+1, ix});
           } 
        }
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>K;
    cout<<bfs(N);

    return 0;
}
