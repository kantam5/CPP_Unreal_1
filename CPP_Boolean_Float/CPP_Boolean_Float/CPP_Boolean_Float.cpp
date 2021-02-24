#include <iostream>
using namespace std;

// 불리언과 실수

// Boolean 참/거짓
bool isHighLevel = true;
bool isPlayer = true;
bool isMale = false;

// [Note]
// 사실 bool은 그냥 1바이트 정수에 불과 1, 0
// 정수에서 다루지 않은 이유
// -> 일리 있다. 어셈블리에서 bool은 존재하지 않음
// bool만 봐도 참/거짓 둘 중 하나라는 힌트를 준다. (가독성)
int isFemale = 1;

// bool < 1바이트 정수

// 실수(부동소수점)
// flaot double
// 3.14

// 부동소수점
// .을 유동적으로 움직여서 표현하는 방법
// 3.14 = 0.314 * 10
// 314... (유효숫자)  1 (지수)

// float 부호(1) 지수(8) 유효숫자(23) = 32비트 = 4바이트
// double 부호(1) 지수(11) 유효숫자(52) = 64비트 = 8바이트

float attackSpeed = -3.375;	// float는 뒤에 f를 붙여 4byte
double attackSpeed2 = 123.456;	// 8byte

// ex) -3.375라는 값을 저장
// 1) 2진수 변환 = (3) + (0,375) = 0b11 + 0b0.011 = 0b11.011
// 0.375 = 0.5 * 0 + 0.245 * 1 + 0.125 * 1 = 0b0.011
// 2) 정규화 0b1.011 * 2^1
// 1(부호) 1(지수) 1011(유효숫자)
// 단 지수는 unsigned byte라고 가정하고 숫자+127 만들어줌
// 예상 결과 : 0b 1 10000000 1011000 0000 0000 0000 0000

// 부동소수점은 언제나 근사값
// 특히 수가 커질 수록 오차 범위도 매우 커진다. 
// 실수 2개를 == 으로 비교하는 것은 지양

int main()
{
	cout << isHighLevel << endl;
}