#include <bits/stdc++.h>
using namespace std;

int a,b,k;
int dp[1000001];
bool visited[1000001];

int cal(int n){
    
    int ret=0;
    int d1,d2;
    while(n){
        d1=1;
        d2=n%10;
        for(int i=0;i<k;++i) d1*=d2;
        ret+=d1;

        n/=10;
    }
    
    return ret;
}

int solve(int n){
    if(n>1000000) return solve(cal(n));
    if(dp[n]!=-1) return dp[n];

    vector<int> p;
    if(visited[n]){
        p.push_back(n);
        int mn=n;
        int nxt = cal(n);
        while(nxt!=n){
            p.push_back(nxt);   
            mn=min(mn,nxt);
            nxt=cal(nxt);
        }

        for(int i:p) dp[i] = mn;

        return mn;
    }

    
    visited[n]=1;
    int ret = min(n,solve(cal(n)));
    visited[n]=0;

    return dp[n]=ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    cin>>a>>b>>k;
    
    memset(dp,-1,sizeof(dp));

    int ans=0;
    for(int i=a;i<=b;++i)
        ans+=solve(i);

    cout<<ans;

    return 0;
}