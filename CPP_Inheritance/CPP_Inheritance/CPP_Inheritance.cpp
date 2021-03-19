#include <iostream>
using namespace std;

// 객체지향
// - 상속성
// - 은닉성
// - 다형성

// 메모리
// [ [Player] ]
// [  Knight  ]

// 상속(Inheritance) -> 부모가 자식에게 유산을 물려주는 것

// 생성자/소멸자
// -> Knight를 호출하면 Player의 생성자가 호출되나 Knight의 생성자가 호출되나
// -> 그냥 둘다 호출하자
class GameObject
{
public:
	int _object;
};

class Player : GameObject
{
public:
	Player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;
		cout << "player의 기본 생성자 호출" << endl;
	}
	Player(int hp)
	{
		_hp = hp;
		cout << "player(int hp) 호출" << endl;
	}
	~Player()
	{
		cout << "Player의 소멸자 호출" << endl;
	}

	void Move()
	{
		cout << "Player Move 호출" << endl;
	}
	void Attack() 
	{ 
		cout << "Player Attack 호출" << endl; 
	}
	void Die()
	{
		cout << "Player Die 호출" << endl;
	}
public:
	int _hp;
	int _attack;
	int _defence;
};

class Knight : public Player
{
public:
	Knight() 
	{
		// 선처리 영역
		// Player의 생성자를 호출
		_stamina = 0;
		cout << "Knight의 기본 생성자 호출" << endl;
	}
	Knight(int stamina) : Player(100)
	{
		_stamina = stamina;
		cout << "knight(int stamina) 기본 생성자 호출" << endl;
	}
	~Knight()
	{
		cout << "Knight의 소멸자 호출" << endl;
		// 후처리 영역
		// Player의 소멸자 호출
	}

	// 재정의: 부모쪽의 함수를 재정의
	void Move()
	{
		cout << "Knight Move 호출" << endl;
	}

public:
	int _stamina;
};

class Mage : public Player
{
public:
	Mage(int mp)
	{
		_mp = mp;
	}

public:
	int _mp;
};

int main()
{
	Knight k(100);
	// 실질적인 어셈블리에선 Knight의 생성자가 먼저 호출되고 후에 Player가 호출
	// 생성자의 안에들어가서 바로 Player의 기본 생성자 호출 (선처리)
	k._hp = 100;
	k._attack = 10;
	k._defence = 5;
	k._stamina = 50;

	/*k.Attack();
	k.Move();
	k.Player::Move();*/

	return 0;
}
