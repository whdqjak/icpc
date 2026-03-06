#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;


int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,S;

    cin>>N>>S;

    arr[0]=0;
    for(int i=1;i<=N;++i){
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }

    int p1,p2;

    p1=0;
    p2=1;

    int c;
    int ans = INF; 
    while(p2>p1 && p2<=N){
        c = arr[p2]-arr[p1];

        if(c<S) ++p2;
        else{
            if(ans>p2-p1) ans = p2-p1;
            ++p1;
        }
    }

    if(ans==INF) cout<<0;
    else cout<<ans;

    return 0;
}