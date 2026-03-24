#include <bits/stdc++.h>
using namespace std;

int A[100];
int C[100];
int dp[10000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N; ++i) cin >> C[i];

    int maxC = 0;
    for(int i = 0; i < N; ++i) maxC += C[i];

    for(int i = 0; i < N; ++i){
        for(int c = maxC; c >= C[i]; --c){
            dp[c] = max(dp[c], dp[c - C[i]] + A[i]);
        }
    }

    for(int c = 0; c <= maxC; ++c){
        if(dp[c] >= M){
            cout << c;
            break;
        }
    }

    return 0;
}