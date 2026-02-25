# boj 1504_특정한 최단 경로

## 문제
-특정한 정점들을 꼭 지나는 최단경로 구하기 문제

## 해결방법
-a,b정점을 지나야 한다면 그때 최단거리는
1-a까지의 최단경로
+a-b까지의 최단경로
+b-N까지의 최단경로
이다(a랑 b는 바뀔 수 있음 그래서 비교해줘야함)

int dijkstraF2(int a, int b){
    vector<int> dist1 = dijkstraF(1);
    if(dist1[a]==INF || dist1[b]==INF) return -1;
    vector<int> distN = dijkstraF(N);
    if(distN[a]==INF || distN[b]==INF) return -1;
    vector<int> distA = dijkstraF(a);
    if(distA[b]==INF) return -1;

    int m1 = dist1[a]+distN[b]+distA[b]; //a에서 b로
    int m2 = dist1[b]+distN[a]+distA[b]; //b에서 a로

    return m1<m2?m1:m2;
}