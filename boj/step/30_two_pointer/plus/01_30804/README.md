# boj 30804_과일 탕후루

## 문제

## 스트레스 받은 점
-일단 문제를 스스로 못풀어서 개빡(양 끝에서 해볼려 했음 계속)

-인덱스 가지고 움직일 때 차근차근 생각하기....
(대충 생각할려다 엄청 헤맴!!!!)
while(r<N){
        while(r<N && k<3){  //되는데까지 늘리기
            ++r;
            if(idxCnt[arr[r]]==0) ++k;
            ++idxCnt[arr[r]];
        }
        ans=max(ans, r-l);

        while(l<r && k>2){  //최대한 줄이기(시작점 찾기)
            --idxCnt[arr[l]];
            if(idxCnt[arr[l]]==0) --k;
            ++l;
        }
    }
