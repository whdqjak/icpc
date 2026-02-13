#include <bits/stdc++.h>
using namespace std;

int N,M;
int tmtBox[1000][1000];
int day[1000][1000];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(queue<pair<int, int>>& nxt){

    pair<int, int> u;
    int ux, uy;
    while(!nxt.empty()){
        u = nxt.front();
        nxt.pop();

        for(int i=0;i<4;++i){
            ux = u.first + dx[i];
            uy = u.second + dy[i];
            if(0<= ux && ux <N && 0<=uy && uy<M
                && tmtBox[ux][uy]==0 ){
                    tmtBox[ux][uy] = 1;
                    day[ux][uy] = day[u.first][u.second]+1;
                    nxt.push({ux,uy});
                }
        }
    }

    int ans=0;

    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(tmtBox[i][j]==0) return -1;
            if(day[i][j]>ans) ans = day[i][j];
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>M>>N;

    queue<pair<int,int>> q;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>tmtBox[i][j];
            if(tmtBox[i][j]==1){
                day[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    cout<<bfs(q);

    return 0;
}
