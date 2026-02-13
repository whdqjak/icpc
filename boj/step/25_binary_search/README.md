# 이분탐색
정렬되어 있을 때 쓸 수 있음.

## 재귀

## 비재귀
-반복문을 통해서 (l,r) 범위 업데이트 시켜주기

-이분탐색의 형태
while (l < r) {
    mid = (l + r) / 2;

    if (조건 만족)
        r = mid;
    else
        l = mid + 1;
}
return r;

while (l <= r) {
    mid = (l + r) / 2;

    if (조건 만족)
        r = mid - 1;
    else
        l = mid + 1;
}
return r;

두 개 잘 구분해서 쓰기

## lower_bound(), upper_bound()
-lower_bound는 찾고자 하는 값보다 크거나 같은 값 중 가장 처음 나오는 값 반환.
-upper_bound는 찾고자 하는 값보다 큰 값 중 처음 나오는 값을 반환.
-둘다 반복자(iterator)로 반환한다

-(lower or upper)_bound(시작점, 끝점, 찾을 값)

### 비교 매개변수 사용
-이 두 함수에는 매개변수로 비교인자도 넣을 수 있는데 defualt로는 lower<>()이며 (오름차순)
다음과 같이 greater<>()를 붙여 사용할 수도 있다.

-lower_bound(start, end, target, greater<>())
내림차순 정렬로 target보다 이하인 것 중 최대인 반복자를 반환해준다.

-upper_bound(start, end, target, greater<>())
내림차순 정렬로 target보다 미만인 것 중 최대인 반복자를 반환해준다.