#include <bits/stdc++.h>
using namespace std;

struct xy{
    int x, y;
};

int N, W;
xy event[1001];
int dp[1001][1001];

vector<int> tb;

int cal(xy a, xy b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// a: 경찰차1 마지막 사건, b: 경찰차2 마지막 사건
int f(int a, int b){

    int next = max(a, b) + 1;
    if(next > W) return 0;

    int &ret = dp[a][b];
    if(ret != -1) return ret;

    xy p1 = a==0 ? xy{1,1}:event[a];
    xy p2 = b==0 ? xy{N,N}:event[b];

    // 경찰차1이 처리
    int m1 = f(next, b) + cal(p1, event[next]);

    // 경찰차2가 처리
    int m2 = f(a, next) + cal(p2, event[next]);

    return ret=min(m1,m2);
}

void trace(int a, int b){
    int next = max(a, b) + 1;
    if(next > W) return;

    xy p1 = a==0 ? xy{1,1}:event[a];
    xy p2 = b==0 ? xy{N,N}:event[b];

    int m1 = dp[next][b] + cal(p1, event[next]);
    int m2 = dp[a][next] + cal(p2, event[next]);

    if(m1 < m2){
        cout << 1 << '\n';
        trace(next, b);
    }else{
        cout << 2 << '\n';
        trace(a, next);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> W;

    for(int i = 1; i <= W; ++i){
        cin >> event[i].x >> event[i].y;
    }

    memset(dp, -1, sizeof(dp));

    cout << f(0, 0);
    
    for(int i:tb) cout<<i<<'\n';

    return 0;
}