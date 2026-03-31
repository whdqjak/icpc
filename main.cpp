#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int dp[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;

    for(int i=1;i<=N;++i) cin>>arr[i];
    

    int ans=0;
    int ans_i=0;
    for(int i = 1;i<=N;++i){
        dp[i] = 1;
        for(int j=1;j<i;++j)
            if(arr[j]<arr[i]) dp[i] = max(dp[i], dp[j]+1);
        if(ans<dp[i]) ans=dp[i], ans_i=i;
    }


    cout<<ans<<'\n';

    vector<int> tb;
    
    tb.push_back(arr[ans_i]);

    int c_i=ans_i;
    for(int i = ans_i;i>=1;--i){
        if(arr[c_i]>arr[i] && dp[c_i]-1 == dp[i]) tb.push_back(arr[i]), c_i=i;
    }

    reverse(tb.begin(), tb.end());
    for(int i : tb) cout<<i<<" ";

    return 0;
}