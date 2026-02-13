#include <bits/stdc++.h>
using namespace std;

int l;
int cx,cy;
int tx, ty;
bool visited[300][300];

struct point{
    int x,y;
};

point move1(int x, int y){
    return{x-2,y-1};
}
point move2(int x, int y){
    return{x-2,y+1};
}
point move3(int x, int y){
    return{x-1,y-2};
}
point move4(int x, int y){
    return{x-1,y+2};
}
point move5(int x, int y){
    return{x+2,y-1};
}
point move6(int x, int y){
    return{x+2,y+1};
}
point move7(int x, int y){
    return{x+1,y-2};
}
point move8(int x, int y){
    return{x+1,y+2};
}

point (*moveP[8])(int x, int y) = {move1, move2, move3, move4,
                                    move5, move6, move7, move8};

bool check(int a){
    if(0<=a && a<l) return 1;
    return 0;
}

int bfs(int x, int y){

    if(x==tx && y==ty) return 0;
    

    visited[x][y] = 1;
    queue<pair<int, point>> nxt;
    nxt.push({0,{x,y}});

    pair<int, point> u;
    point t, ut;
    while(!nxt.empty()){
        u = nxt.front();
        nxt.pop();
        ut = u.second;
        for(int i = 0;i<8;++i){
            t = moveP[i](ut.x, ut.y);
            if(t.x==tx && t.y==ty) return u.first+1;
            if(check(t.x)&&check(t.y)&&!visited[t.x][t.y]){
                visited[t.x][t.y] = 1;
                nxt.push({u.first+1, t});
            }
        }
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){

        memset(visited, 0, sizeof(visited));

        cin>>l;
        cin>>cx>>cy;
        cin>>tx>>ty;
        cout<<bfs(cx, cy)<<'\n';
    }
    

    return 0;
}
