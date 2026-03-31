#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;


    dp[1]=0;

    for(int i=2;i<=N;++i){
        dp[i]=dp[i-1]+1;
        if(i%2==0) dp[i]=min(dp[i],dp[i/2]+1);
        if(i%3==0) dp[i]=min(dp[i],dp[i/3]+1);
    }

    cout<<dp[N]<<'\n';

    vector<int> tb;

    tb.push_back(N);
    for(int i=N;i>1;){
        if(dp[i]-1==dp[i-1]) --i;
        else if(i%2==0 && dp[i]-1==dp[i/2]) i/=2;
        else if(i%3==0 && dp[i]-1==dp[i/3]) i/=3;
        else{
            cout<<"error\n";
            return 0;
        }
        tb.push_back(i);
    }

    for(int i : tb) cout<<i<<' ';

    return 0;
}