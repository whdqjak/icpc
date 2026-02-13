#include <bits/stdc++.h>
using namespace std;

int N, M;
bool arr[50][50];
bool visited[50][50];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool check(int l,int a, int r){
    if(l<a && a<r) return 1;
    return 0;
}

void dfs(int y, int x){
    visited[y][x] = 1;

    int iy, ix;
    for(int i=0;i<4;++i){
        iy = y+dy[i];
        ix = x+dx[i];
        if(check(-1,iy,N) && check(-1,ix,M) && arr[iy][ix] && !visited[iy][ix]){
            dfs(iy, ix);
        }
    }
}

int dfsAll(){
    int cnt = 0;
    memset(visited, 0, sizeof(visited));

    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(arr[i][j] && !visited[i][j]) dfs(i, j), ++cnt;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    int K;
    int a, b;
    while(T--){

        memset(arr, 0, sizeof(arr));

        cin>>M>>N>>K;
        for(int i=0;i<K;++i){
            cin>>a>>b;
            arr[b][a] = 1;
        }
        cout<<dfsAll()<<'\n';
    }

    return 0;
}
