#pragma once
// #include "Monster.h"

// class Monster;

// Ŭ�����ȿ� Ŭ������ �ִٸ� �� ����Ʈ���� �� �� ����
// -> �̿ϼ��� Ŭ����
// ������ �����ͷ� �ִٸ� �� ����Ʈ���� �� �� �ִ�.
//

class Player
{
public:
	void KillMonster();
	void KillMonster2();
	// {
		// Monster�� ���赵�� �������� hp�� ����ִ��� �𸥴�.
		// -> include�ؾߵ�
		// _target2->_hp = 0;
	// }

public:
	int _hp;
	int _attack;

	// Monster _target;
	class Monster* _target2;	// ���漱���� �տ� class ����
};

