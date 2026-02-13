#include <bits/stdc++.h>
using namespace std;

int N,M;
string s[100];
bool visited[100][100];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool check(int l, int a, int r){
    if(l<a && a<r) return 1;
    return 0;
}

int bfs(int x, int y){
    visited[x][y] = 1;

    queue<pair<int, pair<int,int>>> nxt;
    nxt.push({1, {x, y}});
    pair<int, pair<int,int>> u;
    int ix, iy;

    int nn, ux, uy;
    while(!nxt.empty()){
        u = nxt.front();
        nxt.pop();
        
        ux = u.second.first;
        uy = u.second.second;
        nn = u.first;
        for(int i=0;i<4;++i){
            ix = ux+dx[i];
            iy = uy+dy[i];
            if(ix==N-1 && iy == M-1) return nn+1;
            if(check(-1,ix,N) && check(-1,iy,M) && (s[ix][iy]=='1') && !visited[ix][iy]){
                visited[ix][iy] = 1;
                nxt.push({nn+1,{ix,iy}});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    for(int i=0;i<N;++i) cin>>s[i];

    cout<<bfs(0,0);

    return 0;
}
