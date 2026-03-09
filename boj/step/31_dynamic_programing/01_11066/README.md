# boj 11066_파일 합치기

## 문제
-파일들의 목록이 주어졌을 때 파일들을 합치는 비용이 가장 작은 값 구하기
-남은 파일이 한개가 될 때까지 합치기
-파일을 합치는 비용은 합치는 파일의 크기의 합
-인접한 파일들끼리만 합칠 수 있음
-한번에 최대 두개 합칠 수 있음

## 재귀, 비재귀
-재귀는 상당히 직관적임
-비재귀는 잘 모르겠다면 일단 재귀먼저 짜고 비재귀로 짜기..



## 오해
#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

int fileArr[500];

// 500+250+... <=1000, 1000*10000 = 10^7 int 충분~
int solve(int* arr, int n){
    priority_queue<int> pq; // {-값}
    
    for(int i=0;i<n;++i) pq.push(-arr[i]);

    int k1,k2,k3;
    int ans = 0;
    while(pq.size()>1){
        k1 = -pq.top();
        pq.pop();
        k2 = -pq.top();
        pq.pop();

        k3 = k1+k2;
        pq.push(-k3);
        ans +=k1+k2;
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    int k;
    while(T--){
        cin>>k;
        for(int i=0;i<k;++i) cin>>fileArr[i];
        cout<<solve(fileArr, k)<<'\n';
    }

    return 0;
}