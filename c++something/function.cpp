//c++ 함수 정리(자료구조 이외)

#include <bits/stdc++.h>
using namespace std;

int arr[100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //람다 함수
    [capture](parameters) -> return_type {
        body
    };
    
    auto f = [&](int a, int b){
        return a+b;
    }
    cout<<f(3,4);
    //[] 안에다가 함수에서 쓸 변수의 범위를 정해줄 수 있음
    //[&], [=], [a,b,c,]


    //--------------------


    //memset함수
    memset(arr, 0, sizeof(arr));
    // 바이트 단위로 초기화 시킨다
    // 그래서 0이나 -1로 초기화 할때만 실제값도 0이나 -1이다
    // 대신 bool자료형은 한개의 크기가 1바이트여서 1로 초기화 해도 괜찮다.
    

    //--------------------


    //bound(upper, lower) 함수
    int std;
    upper_bound(arr, arr+N,std);
    // std보다 큰 값이 처음 나타나는 위치 반환
    lower_bound(arr, arr+N,std);
    // std이상이 처음 나타나는 위치 반환

    
    //--------------------



    //
    return 0;
}