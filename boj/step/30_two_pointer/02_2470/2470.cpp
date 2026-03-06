#include <bits/stdc++.h>
#define INF (int)2e9
using namespace std;

int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;++i) cin>>arr[i];

    sort(arr,arr+n);

    int l=0;
    int r=n-1;

    int c, ans, ansl=0, ansr=n-1;
    ans = INF+1;
    while(l<r){
        c=arr[l]+arr[r];
        if(abs(c)<ans){
            ans = abs(c);
            ansl = l;
            ansr = r;
        }
        if(c>0) --r;
        else if(c<0) ++l;
        else break;
    }

    cout<<arr[ansl]<<' '<<arr[ansr];

    return 0;
}