#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

int arr[200000];
int idxCnt[10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin>>N;

    for(int i=0;i<N;++i) cin>> arr[i];

    int l,r,k,ans;
    l=k=ans=0;
    r=-1;
    memset(idxCnt, 0, sizeof(idxCnt));
    while(r<N){
        while(r<N && k<3){  //되는데까지 늘리기
            ++r;
            if(idxCnt[arr[r]]==0) ++k;
            ++idxCnt[arr[r]];
        }
        ans=max(ans, r-l);

        while(l<r && k>2){  //최대한 줄이기(시작점 찾기)
            --idxCnt[arr[l]];
            if(idxCnt[arr[l]]==0) --k;
            ++l;
        }
    }
    
    cout<<ans;

    return 0;
}