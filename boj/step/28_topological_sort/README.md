# 위상정렬
-위상정렬
방향 그래프(DG)에서 간선으로 주어진 정점 간 선후관계를 위배하지 않도록 나열하는 정렬

-위상정렬의 기본흐름
그래프에서 가장 앞에 올 수 있는 정점 하나를 택한 뒤(A)
택한 정점을 그래프에서 제거 후 (A)행동을 함
모든 정점이 다 사라질 때까지 반복

-위상정렬을 할려면 기본적으로 DAG이여야 함(사이클이 존재하지 않는 방향 그래프)

## 구현
vector<int> topoSort(){     

    queue<int> indeg;   //우선순위가 0인 녀석들
                        //화살표를 0개받고 있는 녀석들

    for(int i=1;i<=N;++i){  //각 정점들에 대해 def(받는 화살표 수) 계산
        for(int nxt : adj[i]){
            ++deg[nxt];
        }
    }
    for(int i=1;i<=N;++i)   //큐에 우선순위 0인애들
        if(deg[i]==0) indeg.push(i);    //넣어주기

    vector<int> result;
    int cur;
    while(!indeg.empty()){  //큐가 비기전까지 계속
        cur = indeg.front();
        indeg.pop();
        result.push_back(cur);  //결과 배열에 추가

        for(int nxt : adj[cur]){    //deg업데이트 해주기
            --deg[nxt];
            if(deg[nxt]==0) indeg.push(nxt);
        }
    }

    return result;
}