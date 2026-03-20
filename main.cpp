#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

int N;
int wt[30];
bool dp[15001][30];
bool check[15001][30];

bool f(int bw, int b){   //a에서 b까지로 bw를 만들 수 있는지 없는지

    if(bw>15000) return 0;
    if(b<0) return (bw==0);

    bool& ret = dp[bw][b];
    if(check[bw][b]) return ret;

    check[bw][b]=1;
    ret = 0;
    
    ret |= f(bw, b-1);

    ret |= f(bw+wt[b], b-1);

    ret |= f(abs(bw-wt[b]), b-1);

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N;
    for(int i=0;i<N;++i) cin>>wt[i];

    int M;
    cin>>M;

    int bw;
    for(int i=0;i<M;++i){
        cin>>bw;
        if(f(bw,N-1)) cout<<"Y ";
        else cout<<"N ";
    }
    
    return 0;
}