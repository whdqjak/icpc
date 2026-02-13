#include <bits/stdc++.h>
using namespace std;

vector<int> cpt[100001];
bool visited[100001];

int bfs(int x){

    int cnt=0;

    visited[x] = 1;
    
    queue<int> q;
    q.push(x);

    int u;
    while(!q.empty()){
         u = q.front();
         q.pop();
         for(int i: cpt[u]){
            if(!visited[i]){
                visited[i] = 1;
                ++cnt;
                q.push(i);
            }
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin>>N>>M;

    int a,b;
    for(int i=1;i<=M;++i){
        cin>>a>>b;
        cpt[a].push_back(b);
        cpt[b].push_back(a);
    }

    cout << bfs(1);

    return 0;
}