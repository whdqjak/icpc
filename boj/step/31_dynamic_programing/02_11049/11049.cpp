#include <bits/stdc++.h>
#define INF (long long)3e18
using namespace std;

pair<int, int> m[500];
long long dp[500][500];

long long f(int a, int b){

    if(a == b) return 0;

    long long& ret = dp[a][b];
    if(ret!=INF) return ret;

    for(int i = a; i < b; ++i){
        ret = min(ret, 
            f(a, i) + f(i+1, b) + 1LL * m[a].first * m[i].second * m[b].second
        );
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i)
        cin >> m[i].first >> m[i].second;

    fill(dp[0], dp[0]+500*500, INF);
    cout << f(0, N-1);

    return 0;
}