#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

int N,M;

int ground[500][500];
int dp[500][500];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

// int f(int x, int y){
    
//     if(x==N-1 && y==M-1) return 1;

//     int& ret=dp[x][y];
//     if(ret!=-1) return ret;


//     ret = 0;
//     int ux,uy;
//     for(int i=0;i<4;++i){
//         ux = x+dx[i];
//         uy = y+dy[i];
//         if(ux<0 || uy<0 || ux>=N || uy>=M ||
//             ground[x][y]<=ground[ux][uy]) continue;

//         ret+=f(ux,uy);
//     }

//     return ret;
// }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>N>>M;

    for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            cin>>ground[i][j];

    memset(dp, -1, sizeof(dp));


    dp[N-1][M-1]=1;

    int ux,uy;
    for(int i=N-2;i>=0;--i){
        for(int j=M-2;j>=0;--j){
            dp[i][j]=0;
            for(int d=0;d<4;++d){
                ux = i+dx[d];
                uy = j+dy[d];
                if(ux<0 || uy<0 || ux>=i || uy>=j ||
                     ground[x][y]>=ground[ux][uy]) continue;
                    
                dp[i][j]+=dp[ux][uy];
            }
        }
    }


    cout<<f(0,0);
    
    return 0;
}