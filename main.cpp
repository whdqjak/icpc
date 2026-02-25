#include <bits/stdc++.h>
using namespace std;

int min(int a, int b){
    return a<b?a:b;
}

int dp[50001];
int f(int n){
    
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i<=n;++i){
        dp[i] = 5;
        for(int j = 1;j*j<=i;++j){
            dp[i] = min(dp[i], dp[i-j*j]+1);    
        }
    }

    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    cout<<f(n);

    return 0;
}