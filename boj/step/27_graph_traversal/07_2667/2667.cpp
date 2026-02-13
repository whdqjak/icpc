#include <bits/stdc++.h>
using namespace std;

int N;
int arr[50][50];
bool visited[50][50];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y){

    if(x==N || x==-1 || y == N || y==-1) return 0;

    visited[x][y] = 1;

    int cnt = 1;
    for(int i=0, ix, iy;i<4;++i){
        ix = x + dx[i];
        iy = y + dy[i];
        if(0<=ix && ix < N && 0<=iy && iy < N && !visited[ix][iy] && arr[ix][iy]==1){
            cnt += dfs(ix, iy);
        }
    }

    return cnt;
}

void solveF(){

    vector<int> ans;
    int cnt=0;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(!visited[i][j]&&arr[i][j]==1) ans.push_back(dfs(i, j)), ++cnt;
        }
    }

    sort(ans.begin(), ans.end());
    int len = ans.size();
    cout<<cnt<<'\n';
    for(int i=0;i<len;++i) cout<<ans[i]<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    string s;
    for(int i=0;i<N;++i){
        cin>>s;
        for(int j=0;j<N;++j){
            arr[i][j] = s[j]-'0';
        }
    }

    solveF();

    return 0;
}
