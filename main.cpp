#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

bool ets[(int)4e6 + 1];
void etsF(int n){
    
    memset(ets, 1, sizeof(ets));
    ets[0]=ets[1]=0;

    for(int i=2;i*i<=n;++i){
        if(ets[i])
            for(int j=i*i;j<=n;j+=i) ets[j]=0;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;

    etsF(N);

    vector<int> prime;

    prime.push_back(0);
    for(int i=2;i<=N;++i)
        if(ets[i]) prime.push_back(i);

    long unsigned int l,r;

    l=r=0;
    int c = prime[0];
    int cnt=0;
    while(l<=r && r<prime.size()){
        if(c>N)
            c-=prime[l++];
        else if(c<N)
            c+=prime[++r];
        else{
            ++cnt;
            c-=prime[l++];
            c+=prime[++r];
        }
    }

    cout<<cnt;

    return 0;
}