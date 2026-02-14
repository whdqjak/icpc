#include <bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
    int c;  // 벽을 부술 수 있는 기회 (1: 아직 가능, 0: 이미 사용)
};

int N, M;
string Map[1001];
int visited[1001][1001][2];

int dx[4] ={0,0,1,-1};
int dy[4] ={1,-1,0,0};

int bfs(){
    queue<point> nxt;
    nxt.push({0,0,1});
    visited[0][0][1] = 1;

    while(!nxt.empty()){
        point u = nxt.front();
        nxt.pop();

        if(u.x == N-1 && u.y == M-1)
            return visited[u.x][u.y][u.c];

        for(int i=0;i<4;++i){
            int ux = u.x + dx[i];
            int uy = u.y + dy[i];

            if(ux < 0 || uy < 0 || ux >= N || uy >= M) continue;

            if(Map[ux][uy] == '1'){
                if(u.c == 1 && visited[ux][uy][0] == 0){
                    visited[ux][uy][0] = visited[u.x][u.y][1] + 1;
                    nxt.push({ux, uy, 0});
                }
            }
            else{
                if(visited[ux][uy][u.c] == 0){
                    visited[ux][uy][u.c] = visited[u.x][u.y][u.c] + 1;
                    nxt.push({ux, uy, u.c});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for(int i=0;i<N;++i)
        cin >> Map[i];

    cout << bfs();

    return 0;
}
