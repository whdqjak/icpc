# boj 7562_나이트의 이동

## 문제
-현재 나이트의 좌표가 주어지고 목표 좌표가 주어졌을 때
목표 좌표에 나이트를 이동시키는 문제(최소한의 이동으로)

## 해결방법
-bfs로 해결하면 됨

## 구현 방법(+구현실수)
-함수 포인터 배열을 써봤다
struct point{
    int x,y;
};

point move1(int x, int y){
    return{x-2,y-1};
}
point move2(int x, int y){
    return{x-2,y+1};
}
point move3(int x, int y){
    return{x-1,y-2};
}
point move4(int x, int y){
    return{x-1,y+2};
}
point move5(int x, int y){
    return{x+2,y-1};
}
point move6(int x, int y){
    return{x+2,y+1};
}
point move7(int x, int y){
    return{x+1,y-2};
}
point move8(int x, int y){
    return{x+1,y+2};
}

point (*moveP[8])(int x, int y) = {move1, move2, move3, move4,
                                    move5, move6, move7, move8};

-구조체를 쓸 때 .대신 , 오타(그 전에도 꽤 있었음)

-아래코드에서 이런식으로 쓰는것보다 dist배열을 하나 만드느게 더 효율적이라고 한다
queue<pair<int, point>> nxt;

queue<point> nxt;
int dist[][]    //방문배열을 방문순서(정확히는 번째 수)로 넣으면 될듯

-변수 이름 관련해서 많이 부족한듯(쓸데도 헷갈리는것도 있고 이름을 멀로 해야할지 헷갈림)
-memset()은 항상 0이나 1로 초기화 할때만 쓰기!(여러번 강조하면 좋아서 쓴다)