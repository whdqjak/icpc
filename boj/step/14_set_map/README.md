# 집합과 맵

## 집합
set<T> s;

-원소 중복 허용 안함
-자동 정렬
-균형 이진 탐색 트리로 구현되어 있음
-모든 연산은 log(N)임

-주요 함수
insert()    값 삽임
erase() //값 삭제
find()  //iterator 반환
count() //1,0

## 맵
map<key, Value> m;

-key만 중복 불가
-key기준으로 자동 정렬
-균형 이진 탐색 트리로 구현되어 있음
-모든 연산 log(N)

-주요 함수
insert({key,value}) or m[key] = value; (없으면 자동생성)    //값 삽입
map[key];(배열처럼 접근, 만약 없으면 0으로 자동생성)

나머지 탐색이나 삭제 이런건 set이랑 똑같음

## 정렬없는 버전
unordered_set
unordered_map