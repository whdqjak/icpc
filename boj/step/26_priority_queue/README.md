# 우선순위 큐
-우선순위 큐는 가장 우선순위가 높은 원소를 O(log N)에 꺼낼 수 있는 자료구조다.
-STL priority_queue는 기본적으로 힙(heap) 으로 구현됨

## 초기화, 선언
-priority_queue<int> pq; // 빈 최대힙 선언
-priority_queue<int> pq2(pq); // 복사 생성

-초기화(비우기)
pq = priority_queue<int>(); // 가장 간단
priority_queue<int>().swap(pq); // 빠르고 확실

## 최대힙, 최소힙
-priority_queue<int> pq; //최대 힙
priority_queue<int>, vector<int>, less<int>> pq  // 최대 힙 원래 형태
-priority_queue<int>, vector<int>, greater<int>> pq; //최소 힙

-less 와 greater는 내부적으로 >,< 연산자를 쓴다.
만약 int가 아닌 >,< 가 정의되어 있지 않은 자료형을 쓴다면 따로 정의를 해줘야 한다!


-PS에서는 부호 반전으로 최소힙을 흉내 내기도 한다.
priority_queue<int> pq;
pq.push(-x);
int val = -pq.top();

## 커스텀?
-priority_queue<type>, vetor<type>, cmp<type>>
<자료형, 컨테이너, 비교자> 형식인데 컨테이너는 vector를 쓴다.(배열 안됨, 다른것도 안쓰는게 맞음)

-비교자는 우선순위를 무엇으로 할지 자유롭게 정할 수 있음 ex) 절댓값 힙.
-주의할 점은 sort에서는 a < b 이면 오름차순 이었지만(왼쪽 원소 < 오른쪽 원소 느낌)
우선순위 큐는 a < b 이면 내림차순(최대힙) 이다(a보다 b가 top() 느낌)

**비교자 기준은 나중에 다시 확인해보기!



struct Node {
    int x, y;

    bool operator < (const Node& o) const {
        return x < o.x; // x가 큰 것이 우선(top())
    }

    bool operator > (const Node& o) const {
        return x > o.x; // x가 작은 것이 우선
    }
};
priority_queue<<Node>, vector<Node>, (less or greater)<Node>>> pq;


struct cmp {
    bool operator()(Node a, Node b) {
        return a.x > b.x; // 최소힙
    }

-------------------OR---------------------
    
    bool operator()(Node a, Node b) {
        return a.x < b.x; // 최대힙
    }
};
priority_queue<Node>, vector<Node>, cmp> pq;
