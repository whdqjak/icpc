#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
vector<pair<int, int>> dp;  //{값, 인덱스}
int nxt[1000000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;

    for(int i=0;i<N;++i) cin>>arr[i];

    pair<int, int> x;
    int idx;

    for(int i=0;i<N;++i){
        x.first = arr[i];
        x.second = i;

        idx = lower_bound(dp.begin(), dp.end(), x,
        [](const pair<int,int>& a, const pair<int,int>& b){
        return a.first < b.first;
        })-dp.begin();
        
        if(idx==0) nxt[i] = -1;
        else nxt[i] = dp[idx-1].second;

        if(idx==dp.size()) dp.push_back(x);
        else dp[idx] = x;

    }

    cout<<dp.size()<<'\n';

    vector<int> ans;

    int c = dp[dp.size()-1].second;
    while(1){
        ans.push_back(arr[c]);
        c=nxt[c];
        if(c==-1) break;
    }

    reverse(ans.begin(), ans.end());
    for(int i:ans) cout<<i<<' ';

    return 0;
}