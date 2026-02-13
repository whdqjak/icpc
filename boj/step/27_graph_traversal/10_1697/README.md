# boj 1697_숨바꼭질

## 문제
-수직선상에서 수빈이와 동생의 좌표가 각각 주어질 때 수빈이가 동생을 찾아야 함
-수빈이는 현재좌표X 에서 {x-1, x+1, 2*x} 3가지 방식으로 움직일 수 있음
-움직일 때마다 1초가 지나가는데 동생을 찾을 수 있는 가장 빠른 시간 구하는 문제

## 알게된 점
-아무래도 최단거리 관련해서 bfs가 많이 쓰이는 것 같다(+시간 흐름에도)
-이동방식이 좀 복잡해질 때 각 움직임을 함수로 구현할 수 있고, 각 함수를 배열에 저장할 수 있다(함수 배열), 함수 배열도 일반 배열처럼 원소도 바꾸고 다 할 수 있음.

struct Point {
    int x, y;
};

// 각 방향 이동 함수
Point down(Point p){ return {p.x + 1, p.y}; }
Point up(Point p){ return {p.x - 1, p.y}; }
Point right(Point p){ return {p.x, p.y + 1}; }
Point left(Point p){ return {p.x, p.y - 1}; }

Point (*move[4])(Point) = { down, up, right, left };

for(int d = 0; d < 4; d++){
    Point np = move[d](p);   // 진짜 함수처럼 호출됨
    cout << "dir " << d << " -> "
        << np.x << " " << np.y << "\n";
}

-또한 배열 원소에 변수가 들어갈 수 있다(대신 변수가 먼저 선언되어 있어야 함)
 int dx_f[3] = {ux-1,ux+1,2*ux};
