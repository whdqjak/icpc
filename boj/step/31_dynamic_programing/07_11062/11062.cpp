#include <bits/stdc++.h>
using namespace std;

int arr[1000];
int dp[1000][1000];


int f(bool p, int a, int b){    //p 1근우 0명우, 플레이어가 p일때 근우의 최선점수
    
    if(a>b) return 0;
    if(dp[a][b]!=-1) return dp[a][b];

    int m1 = f(p^1,a+1,b);    //왼쪽 골랐을 때
    int m2 = f(p^1,a,b-1);    //오른쪽 골랐을 때
    
    if(p) return dp[a][b]=max(m1+arr[a], m2+arr[b]);
    return dp[a][b]=min(m1, m2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin>>T;

    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<n;++i) cin>>arr[i];
        
        memset(dp, -1, sizeof(dp));
        cout<<f(1,0,n-1)<<'\n';
    }


    return 0;
}