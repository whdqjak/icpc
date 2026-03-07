//c++ 함수 정리(자료구조 이외)

#include <bits/stdc++.h>
using namespace std;

int arr[100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //memset함수
    //바이트 단위로 초기화 시킨다
    //그래서 0이나 -1로 초기화 할때만 실제값도 0이나 -1이다
    //대신 bool자료형은 한개의 크기가 1바이트여서 1로 초기화 해도 괜찮다.
    memset(arr, 0, sizeof(arr));



    return 0;
}