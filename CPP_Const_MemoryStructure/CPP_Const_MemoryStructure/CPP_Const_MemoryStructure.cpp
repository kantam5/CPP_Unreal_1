#include <iostream>
using namespace std;

// 데이터 연산


unsigned char flag;	// 부호가 없어야 우측 쉬프트가 편하다.

// 한번 정해지면 절대 바뀌지 않을 값들
// constant의 약자인 const를 붙임 (상수화)
// 초기값이 반드시 필요

// 하드코딩하지 말고 상수화 시켜서 쓰자
// .rodata?
// 사실 C++ 표준에서 꼭 그렇게 하라는 말이 없음
// 그냥 컴파일러 마음
// const가 함수 내부에 있다면 스택영역에 만들어진다.
// 함수 밖이면 컴파일러가 단순히 상수로 표시한다.
const int AIR = 0;
const int STUN = 1;
const int POLYMORPT = 2;
const int INVINCIBLE = 3;

// 전역 변수
// [데이터 영역]
// .data (초기값이 있는 경우)
int a = 2;
// .bss (초기값이 없는 경우 혹은 0인 경우)
int b;
// .rodata (읽기 전용 데이터)
const char* msg = "Hello World";

int main()
{
	// [스택 영역]
	int c = 3;	// 한 함수에서의 메모장, 스택메모리를 사용한다.

#pragma region 비트 연산
	// 언제 필요한가
	// 비트 단위의 조작이 필요할 때
	// 게임 서버에서 ID를 줄 때
	// BitFlag

	// - bitwise not
	// 단일 숫자의 모든 비트를 대상으로 0은 1, 1은 0으로 뒤바뀜

	// & bitwise and
	// 두 숫자의 모든 비트 쌍을 대상으로 and 연산을 한다. 

	// | bitwise or
	// 두 숫자의 모든 비트 쌍을 대상으로 or 연산을 한다. 

	// ^ bitwise xor
	// 두 숫자의 모든 비트 쌍으 대상으로 xor연산을 한다.

	// << 비트 좌측 이동
	// 비트열을 N만큼 왼쪽으로
	// 왼쪽의 넘치는 n개의 비트는 버림, 오른쪽의 비트는 0으로 채워진다.
	// *2를 할 때 자주 보이는 패턴

	// >> 비트 우측 이동
	// 비트열을 N만큼 오른쪽으로 이동
	// 오른쪽의 넘치는 N개의 비트는 버림
	// 왼쪽 생성되는 비트는 
	// - 부호 비트가 존재할 경우 부호 비트를 따라감 (부호있는 정수라면 이 부분을 유의)
	// - 아니면 0을 채운다. (unsigned)

	// 0b0000 [무적][변이][스턴][공중부양]
	//무적 상태
	flag = (1 << INVINCIBLE); //0b1000

	// 하드코딩하지 말자

	// 변이 상태를 추가한다. 
	flag |= (1 << POLYMORPT);

	// 무적인지 확인하고 싶다. 다른 상태는 관심없음
	// bitmask
	bool invincible = (flag & (1 << INVINCIBLE)) != 0;

	// 무적이거나 스턴 상태인지
	bool stunOrInvincible = (flag & 0b1010) != 0;

#pragma endregion
}
