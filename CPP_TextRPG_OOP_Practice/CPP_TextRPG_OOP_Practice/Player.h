#pragma once
// #include "Monster.h"

// class Monster;

// 클래스안에 클래스가 있다면 몇 바이트인지 알 수 없다
// -> 미완성된 클래스
// 하지만 포인터로 있다면 몇 바이트인지 알 수 있다.
//

class Player
{
public:
	void KillMonster();
	void KillMonster2();
	// {
		// Monster의 설계도를 보기전엔 hp가 어디있는지 모른다.
		// -> include해야됨
		// _target2->_hp = 0;
	// }

public:
	int _hp;
	int _attack;

	// Monster _target;
	class Monster* _target2;	// 전방선언은 앞에 class 붙음
};

