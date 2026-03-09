#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

int fileArr[500];
int dp[500][500];
int pSum[500];

int solve(int i, int j){
    if(i == j) return 0;
    
    int &ret = dp[i][j];
    if(ret != -1) return ret;
    
    ret = INF;
    
    for(int m=i; m<j; ++m){
        ret = min(ret,
            solve(i,m) + solve(m+1,j) + pSum[j] - (i ? pSum[i-1] : 0));
        }
        
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;
    
    int k;
    while(T--){
        cin>>k;

        for(int i=0;i<k;++i)
            cin>>fileArr[i];

        pSum[0] = fileArr[0];
        for(int i=1;i<k;++i)
            pSum[i] = pSum[i-1] + fileArr[i];

        memset(dp, -1, sizeof(dp));

        cout<<solve(0, k-1)<<'\n';
    }
    
    return 0;
}