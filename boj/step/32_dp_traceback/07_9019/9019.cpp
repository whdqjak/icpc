#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

int calD(int n){
    n*=2;
    return n%10000;
}
int calS(int n){
    --n;
    if(n<0) return 9999;
    return n;
}
int calL(int n){
    int t = n/1000;
    n%=1000;
    n*=10;
    n+=t;
    return n;
}
int calR(int n){
    int t = n%10;
    n/=10;
    return t*1000 + n;
}

bool visited[10000];

int (*dF[4])(int) ={calD, calS, calL, calR};
char dr[4] = {'D','S','L','R'};

int parent[10000];
char how[10000];

vector<char> bfs(int a, int b){

    memset(visited,0,sizeof(visited));

    queue<int> q;
    visited[a] = 1;
    q.push(a);

    int u,v;

    while(!q.empty()){
        u = q.front();
        q.pop();

        if(u==b) break;

        for(int i=0;i<4;++i){
            v = dF[i](u);

            if(!visited[v]){
                visited[v]=1;
                parent[v] = u;
                how[v] = dr[i];
                q.push(v);
            }
        }
    }

    vector<char> r;
    for(int i=b;i!=a;i=parent[i])
        r.push_back(how[i]);

    reverse(r.begin(), r.end());
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;
    
    int a,b;
    vector<char> ans;
    while(T--){
        cin>>a>>b;
        ans = bfs(a, b);
        for(char i : ans) cout<<i;
        cout<<'\n';
    }
    
    return 0;
}