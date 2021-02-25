#include <iostream>
using namespace std;

// 데이터 연산


unsigned char flag;	// 부호가 없어야 우측 쉬프트가 편하다.

int main()
{
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
	flag = (1 << 3); //0b1000

	// 변이 상태를 추가한다. 
	flag |= (1 << 2);

	// 무적인지 확인하고 싶다. 다른 상태는 관심없음
	// bitmask
	bool invincible = (flag & (1 << 3)) != 0;

	// 무적이거나 스턴 상태인지
	bool stunOrInvincible = (flag & 0b1010) != 0;

#pragma endregion
}
