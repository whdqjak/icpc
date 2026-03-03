#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

int arr[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i) cin>>arr[i];

    int x;
    cin>>x;

    sort(arr,arr+n);
    int s=0;
    int e=n-1;

    int c;
    int cnt=0;
    while(s<e){
        c=arr[s]+arr[e];
        if(c>x) --e;
        else if(c<x) ++s;
        else ++cnt, ++s, --e;
    }

    cout<<cnt;

    return 0;
}