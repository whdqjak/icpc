# boj 1450_냅색문제

## 문제
-배열의 부분집합의 원소의 합이 C이하인 부분집합의 갯수 구하는 문제

## 해결방법
-중간에서 만나기 알고리즘
-비트마스크를 이용한 부분집합 순회

## 헷갈리는 부분

-A만 골라지거나 B만 골라지는 경우가 있는지 잠깐 헷갈렸었다.
-그러나 공집합이 껴있었다는것을 생각하지 못했다...
vector<int> A = subset(arr,n1,C);
vector<int> B = subset(arr+n1,n2,C);

sort(B.begin(), B.end());

int ans=0;
int rC;
for(int i : A){
    rC = C-i;
    ans +=upper_bound(B.begin(), B.end(), rC)-B.begin();
}