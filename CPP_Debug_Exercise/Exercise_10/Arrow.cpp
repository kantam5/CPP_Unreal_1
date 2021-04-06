#include "Arrow.h"
#include "Player.h"
#include <iostream>
using namespace std;

Arrow::Arrow(Player* target, int damage) 
	: _target(target), _damage(damage)
{

}

Arrow::~Arrow()
{

}

void Arrow::AttackTarget()
{
	cout << "화살이 적을 피격합니다!" << endl;

	// 공격 대상이 있다면
	if (_target != nullptr)
	{
		// 데미지를 입힌다
		_target->AddHp(-_damage);
		// 가상함수이므로 가상함수 테이블에 접근
		// 이상한 값에 접근 -> 크래쉬
		_target->PrintInfo();
	}
}