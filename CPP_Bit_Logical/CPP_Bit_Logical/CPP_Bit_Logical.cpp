#include <iostream>
using namespace std;

// 데이터 연산
// 

int a = 1;
int b = 2;

bool isSame;
bool isDiffrence;
bool isGreater;
bool isSmaller;

bool test;
int hp = 100;
bool isInvincible;

int main()
{
#pragma region 비교 연산
	// 언제 필요한가?
	// 체력이 0인지 판별
	// 경험치가 100이상이면 레벨업

	// a == b : 같으면 1, 다르면 0을 반환
	isSame = (a == b);
	isDiffrence = (a != b);
	isGreater = (a > b);
	isSmaller = (a < b);

#pragma endregion

#pragma region 논리 연산
	// 조건에 대한 논리적 사고가 필요할 때
	// 로그인할 때 아이디와 비밀번호 둘다 같아야 한다. 
	// 길드 마스터이거나 운영자 계정이면 길드 해산 가능

	// ! not
	test = !isSame;

	// && and
	test = (hp <= 0 && isInvincible == false);	// 죽음

	// || or
	test = (hp > 0 || isInvincible == true);
	test = !(hp <= 0 && isInvincible == false);

#pragma endregion
}
