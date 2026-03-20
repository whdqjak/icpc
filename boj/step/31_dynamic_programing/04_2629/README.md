# boj 2629_양팔저울

## 문제
-주어진 추들과 저울로 구슬의 무게를 맞출 수 있는지 구하는 문제

## 해결방법
-일단 관점은 구슬과 추를 모두 저울에 올려 양쪽 무게가 같으면 구슬의 무게를
구할 수 있는거임

-추들을 0번째부터 i번째까지 썼을 때 w만큼의 무게를 만들 수 있는지
메모이제이션 해서 dp로 풀기

-사용할 무게추를 추가할 때 마다 할 행동들은 왼쪽에 놓기 오른쪽에 놓기 안놓기
ret |= f(bw, b-1);

ret |= f(bw+wt[b], b-1);

ret |= f(abs(bw-wt[b]), b-1);


## 내가 못한 점
-관점에 대한 해결이 안되서 dp 재귀함수 구현이 안됐음.

## 바텀 업
-기존 방법

dp[0][0] = true;

    for(int i=0;i<N;i++){
        for(int j=0;j<=15000;j++){
            if(!dp[i][j]) continue;

            // 1. 안씀
            dp[i+1][j] = true;

            // 2. 더함
            if(j + wt[i] <= 15000)
                dp[i+1][j + wt[i]] = true;

            // 3. 반대쪽
            dp[i+1][abs(j - wt[i])] = true;
        }
    }

    // 이제 dp[N][x] 보면 됨

-다른 방법
추의 갯수를 늘려가면서 그때마다 무게를 만들어서 만들어진 무게들을 저장하는 식

bool dp[15001];
dp[0] = true;

for(int i=0;i<N;i++){
    bool nxt[15001] = {};

    for(int j=0;j<=15000;j++){
        if(!dp[j]) continue;

        nxt[j] = true;
        if(j + wt[i] <= 15000) nxt[j + wt[i]] = true;
        nxt[abs(j - wt[i])] = true;
    }

    for(int j=0;j<=15000;j++) dp[j] = nxt[j];
}