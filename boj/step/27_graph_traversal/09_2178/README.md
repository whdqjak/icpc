# boj 2178_미로 탐색

## 문제
-미로가 이차원 배열로 주어졌을 때 최단거리를 구하는 문제

## 해결방법
-bfs를 통해서 탐색하다가 현재 정점이 도착지점이면 현재 정점의 번째수 return
-현재 정점의 번째 수(트리로 치면 자식 몇대손인지?)를 저장하기 위해서 정점의 위치와 번째 수를 같이 저장,
큐에 현재 정점의 인접 정접을 넣을 때 (번째수+1) 을 같이 넣어주기

queue<pair<int, pair<int,int>>> nxt;
nxt.push({nn+1,{ix,iy}});

## 실수한 점
-아래 코드처럼(ux,uy) 해야 하는데 dfs를 구현하던 것처럼(x,y)로 했음

while(!nxt.empty()){
        u = nxt.front();
        nxt.pop();
        
        ux = u.second.first;
        uy = u.second.second;
        nn = u.first;
        for(int i=0;i<4;++i){

            {ix = ux+dx[i];          //ix = x + dx[i]    //x,y는 bfs의 시작점
            iy = uy+dy[i];          //iy = y + dy[i]    //이건 실수버전임}

            if(ix==N-1 && iy == M-1) return nn+1;
            if(check(-1,ix,N) && check(-1,iy,M) && (s[ix][iy]=='1') && !visited[ix][iy]){
                visited[ix][iy] = 1;
                nxt.push({nn+1,{ix,iy}});
            }
        }
    }