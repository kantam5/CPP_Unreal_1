#include "Player.h"
#include "Monster.h"


void Player::KillMonster()
{
	_target2->_hp = 0;

	// Monster�� ���赵�� �������� hp�� ����ִ��� �𸥴�.
	// [ �ּ� ] -> [ [monsterId][hp][defence] ]
	(*_target2)._hp = 0;

	// ���� �Ȱ��� �ᱹ include�ؾߵ�
	_target2->KillMe();
}

void Player::KillMonster2()
{
	_target2->_hp = 0;
}

// ��� : �����Ȳ���� ���漱���� �ؾߵǴ��� �����Ȳ����
// include�ؾ� �Ǵ���(���� �ʿ��ϴ���)�� �ľ�