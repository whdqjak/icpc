#include <bits/stdc++.h>
using namespace std;

int N,M;
int arr[101];   // 사다리나 뱀이 없으면 0
int visited[101];

int bfs(){

    queue<int> nxt;

    visited[1] = 1;
    nxt.push(1);

    int u, ux;
    while(!nxt.empty()){
        u = nxt.front();
        nxt.pop();

        for(int i=1;i<=6;++i){
            ux = u+i;
            if(ux==100) return visited[u]; //visited[u]+1-1
            if(ux<100 && visited[ux]==0){
                visited[ux]=visited[u]+1;
                if(arr[ux]!=0 && visited[arr[ux]]==0){
                    visited[arr[ux]] = visited[ux];
                    nxt.push(arr[ux]);
                }
                else if(arr[ux]==0){
                    nxt.push(ux);
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N>>M;
    int a, b;
    for(int i=0;i<N;++i){
        cin>>a>>b;
        arr[a] = b;
    }
    for(int i=0;i<M;++i){
        cin>>a>>b;
        arr[a] = b;
    }

    cout<<bfs();

    return 0;
}
