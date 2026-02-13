#include <bits/stdc++.h>
using namespace std;

struct point{
    int x,y,z;
};

int N,M,K;
int tmtBox[100][100][100];
int day[100][100][100];

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,-1,1};
int bfs(queue<point>& nxt){

    point u;
    int ux, uy, uz;
    while(!nxt.empty()){
        u = nxt.front();
        nxt.pop();

        for(int i=0;i<6;++i){
            ux = u.x + dx[i];
            uy = u.y + dy[i];
            uz = u.z + dz[i];
            if(0<= ux && ux <N && 0<=uy && uy<M && 0<=uz && uz<K
                && tmtBox[ux][uy][uz]==0 ){
                    tmtBox[ux][uy][uz] = 1;
                    day[ux][uy][uz] = day[u.x][u.y][u.z]+1;
                    nxt.push({ux,uy,uz});
                }
        }
    }

    int ans=0;
    for(int l=0;l<K;++l){
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                if(tmtBox[i][j][l]==0) return -1;
                if(day[i][j][l]>ans) ans = day[i][j][l];
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>M>>N>>K;

    queue<point> q;
    for(int l=0;l<K;++l){
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                cin>>tmtBox[i][j][l];
                if(tmtBox[i][j][l]==1){
                    day[i][j][l] = 0;
                    q.push({i,j,l});
                }
            }
        }
    }

    cout<<bfs(q);

    return 0;
}
