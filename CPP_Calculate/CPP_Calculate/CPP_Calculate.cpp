#include <iostream>
using namespace std;

// 데이터 연산
// 

int a = 1;
int b = 2;

int main()
{
#pragma region 산술 연산
    // 산술 연산
    // 대입 연산  a = b
    // 사칙 연산

    // 대입 연산
    a = b;   // a에 b를 대입하고 b를 반환하라
    a = (b = 3); // a = 3, b = 3
    
    // 산술 연산
    // 데미지 계산
    // 루프문에서 카운터를 증가 시킨다거나
    a = b + 3;
    a = b / 3;
    a = b % 3;

    a += 3;
    a -= 3;
    a *= 3;
    a /= 3;

    // 증감 연산자
    a++;
    a--;
    b = a++; // b = a  ->  a 1증가
    b = ++a; // a1증가 -> b = a
#pragma endregion 
}
