﻿#include <iostream>
using namespace std;

// 유의사항

// 1) 변수의 유효범위
// 전역 변수
int hp = 100;   // 유효범위 없음
// 스택
// { } 중괄호의 범위가 생존 범위
// 같은 이름을 두번 사용할 때 문제
// 중괄호를 하나 더 사용하여 해결할 수도 있음
// 전역과 지역 변수는 이름이 겹쳐도 괜찮지만 하지않는게 맞다. g_

// 2) 연산의 우선순위
// 조금이라도 애매하면 ()쳐라

// 3) 타입 변환
// 바구니를 교체(형식을 교체)

// 4) 사칙 연산

int main()
{
    {
        int mp = 5;
    }
    // 스택에 들어가있는 변수
    int mp = 100;
    int hp = 20;

    // 짝수 여부
    bool isEven = (hp % 2 == 0);
    // 짝수거나 3으로 나눠지는 값인지
    bool isEvenOrDivBy3 = (hp % 2 == 0) || (hp % 3 == 0);

    short hp2 = hp; // 작은 바구니로 옮기면 윗쪽 비트 데이터가 짤린 상태로 저장
    float hp3 = hp; // 실수로 변환할 때 정밀로 차이가 있기 때문에 데이터 손실
    unsigned int hp4 = hp;  // 비트 단위로 보면 똑같지만, 분석하느 방법이 달라져 이상해짐(부호 비트)

    // 곱셈
    // - 오버플로우 조심
    // int * int = int  ->  int64를 사용하거나 
    // 숫자 잘림 조심

    // 나눗셈
    // - 0으로 나누기 조심

    // 실수 관련
    // 정수끼리 나누기는 정수로 판단하여 소수점 이하는 버린다. 
    // float와 int사이의 나누기나 곱셈은 float로 나온다. 

}