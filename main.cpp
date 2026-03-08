#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

int arr[30];

vector<int> subset(int* arr, int n, int lim){

    vector<int> set;

    int c;
    bool f;
    for(int bit=0;bit<(1<<n);++bit){
        c=0;
        f=1;
        for(int i=0;i<n;++i){
            if(bit&(1<<i)){
                c+=arr[i];
                if(c>lim){
                    f=0;
                    break;
                }
            }
        }
        
        if(f) set.push_back(c);
    }
    return set;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,C;
    cin>>N>>C;

    for(int i=0;i<N;++i) cin>>arr[i];

    int n1 = N/2;
    int n2 = N-n1;

    
    vector<int> A = subset(arr,n1,C);
    vector<int> B = subset(arr+n1,n2,C);

    sort(B.begin(), B.end());

    int ans=0;
    int rC;
    for(int i : A){
        rC = C-i;
        ans +=upper_bound(B.begin(), B.end(), rC)-B.begin();
    }

    cout<<ans;

    return 0;
}