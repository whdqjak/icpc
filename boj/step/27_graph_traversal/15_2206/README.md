# boj 2206_벽 부수고 이동하기

## 문제
-미로찾기 최단거리 문제인데 벽을 한번 부술 수 있다는 설정이 있음

## 구현방식
-visited[좌표][좌표][상태] 형식으로 나타냄
(visited보단 dist(distance)를 쓰는듯?)

-저렇게 나타내야 현재 좌표에서 벽을 부술 기회가 없는지 없는지 구분할 수 있음(같은 거리로 왔어도 부술 수 있는게 이득이니깐)


-또 그 전까진 목표 좌표에 도달했는지 확인을 queue에 넣을 때 했는데
정식은 queue에서 뺄 때 하는거라고 함~
while(!nxt.empty()){
    point u = nxt.front();
    nxt.pop();

    if(u.x == N-1 && u.y == M-1)
        return visited[u.x][u.y][u.c];

    for(int i=0;i<4;++i){
        ...
    }
}