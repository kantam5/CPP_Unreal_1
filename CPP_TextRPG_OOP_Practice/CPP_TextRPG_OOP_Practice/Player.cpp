#include "Player.h"
#include "Monster.h"


void Player::KillMonster()
{
	_target2->_hp = 0;

	// Monster의 설계도를 보기전엔 hp가 어디있는지 모른다.
	// [ 주소 ] -> [ [monsterId][hp][defence] ]
	(*_target2)._hp = 0;

	// 위와 똑같이 결국 include해야됨
	_target2->KillMe();
}

void Player::KillMonster2()
{
	_target2->_hp = 0;
}

// 결론 : 어느상황에서 전방선언을 해야되는지 어느상황에서
// include해야 되는지(당장 필요하느냐)를 파악