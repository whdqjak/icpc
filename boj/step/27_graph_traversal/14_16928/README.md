# boj 16928_뱀과 사다리 게임

## 문제 
-뱀과 사다리 게임에서 사다리와 뱀에 대한 정보가 주어졌을때 주사위(1~6)를 가능한 한 적게 굴려서 도착점에 도착했을 때 주사위 굴린 횟수 구하는 문제

## 실수한 점(+헷갈린 점)
-조건문 잘 보면 다른점 있음

-수정한 거
if(ux==100) return visited[u]; //visited[u]+1-1
if(ux<100 && visited[ux]==0){
    visited[ux]=visited[u]+1;
    if(arr[ux]!=0 && visited[arr[ux]]==0){
        visited[arr[ux]] = visited[ux];
        nxt.push(arr[ux]);
    }
    else if(arr[ux]==0){
        nxt.push(ux);
    }
}

-수정하기 전 꺼
if(ux==100) return visited[u]; //visited[u]-1+1
if(0<=ux && ux<100 && visited[ux]==0){
    visited[ux]=visited[u]+1;
    if(arr[ux]!=0 && visited[arr[ux]]==0){
        visited[arr[ux]] = visited[ux];
        nxt.push(arr[ux]);
    }
    else{
        nxt.push(ux);
    }
}

+의문이었던 점이 있었는데
if(arr[ux]!=0 && visited[arr[ux]]==0)
여기서 방문조건은 빼도 되는거 아닌가 라는 점이었는데
이유는 어차피 방문조건 무시하고 다시 큐에 넣어도 저 길은 정답이 될 수 없기 때문에(최단거리가 아님) 상관없는거 아닌가?(시간은 오래걸릴 수 있어도)

근데 저렇게 해버리면 최단거리로 탐색을 한 정답케이스의 답에 영향을 줄 수 있음(visited[arr[ux]] 값을 바꾸기 때문에)

-좀 더 깔끔한 구현

int nx = ux;
if(arr[nx] != 0)
    nx = arr[nx];

if(visited[nx] == 0){
    visited[nx] = visited[u] + 1;
    nxt.push(nx);
}
