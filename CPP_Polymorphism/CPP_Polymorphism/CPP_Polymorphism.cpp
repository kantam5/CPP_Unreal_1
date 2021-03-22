#include <iostream>
using namespace std;

// 다형성(Polymorphism) = 겉은 똑같은데 기능이 다르게 동작한다.
// - 오버로딩(Overloading) = 함수의 이름의 재사용, 중복정의
// - 오버라이딩(Overriding) = 부모 클래스의 함수를 자식 클래스에서 재정의

// 바인딩(Binding)	- 묶는다
// - 정적 바인딩(static Binding) : 컴파일 시점에 결정
// - 동적 바인딩(Dynamic Binding) : 실행 시점에 결정 // 면접 단골

// 일반 함수는 정적 바인딩을 사용
// 동적 바인딩을 원한다면? 가상 함수(virtual function)

// 그런데 실제 객체가 어떤 타입인지 어떻게 알고 알아서 가상함수를 호출해준걸까?
// - 가상 함수 테이블 (vitable)

// .vftable [] 4바이트(32) 8바이트(64)
// 그 주소를 타고가보면 호출해야될 함수들의 주소가 적혀있을 것이다.
// 객체를 생성할 때 전처리 영역에서 객체에 입력시킨다.

// 순수 가상 함수 : 구현은 없고 인터페이스만 전달되는 용도로 사용하고 싶을 경우
// 추상 클래스 : 순수 가상 함수가 1개 이상 포함되면 바로 추상 클래스로 간주
// - 직접적으로 객체를 만들 수 없게 됨
// - 상속을 받아서 구현을 해야된다.

class Player
{
public:
	Player()
	{
		_hp = 100;
	}

	void Move()
	{
		cout << "Move Player!" << endl;
	}
	virtual void VMove()
	{
		cout << "Move Player!" << endl;
	}
	virtual void VDie()
	{
		cout << "VDie Player!" << endl;
	}
	// 순수 가상 함수
	virtual void VAttack() = 0;
	/*void Move(int a)
	{
		cout << "Move Player! int" << endl;
	}*/

public:
	int _hp;
};

class Knight : public Player
{
public:
	Knight()
	{
		_stamina = 100;
	}

	void Move()
	{
		cout << "Move Knight Player!" << endl;
	}
	// 가상 함수는 재정의를 하더라도 가상 함수다
	virtual void vmove()
	{
		cout << "Move knight player!" << endl;
	}
	virtual void VDie()
	{
		cout << "VDie knight Player!" << endl;
	}
	virtual void VAttack()
	{
		cout << "Attack Knight" << endl;
	}

public:
	int _stamina;
};

class Mage : public Player
{
public:

public:
	int _mp;
};

// [ [Player] ]
// [  Knight  ]
// [Player]
void MovePlayer(Player* player)
{
	// Knight* k = (Knight*)player; 플레이어에서 나이트로 넘어가면 가능은 하겠지만
	// k->_stamina = 100; 일반적으로 플레이어만 넘겨져 왔다면 문제가 발생한다. 

	player->VMove();
	player->VDie();
}

void MoveKnight(Knight* knight)
{
	knight->Move();
}

class Animal
{
	
};
// 동물은 고양이 입니까? 는 말이 안됨 아닐 수도 있다.
class Cat : public Animal
{

};

class Dog : public Animal
{

};

int main()
{
	// Player p;		// 추상 클래스이므로 객체 생성 불가
	// MovePlayer(&p);	// 플레이어는 플레이어다? Yes
	// MoveKnight(&p);	// 플레이어는 기사다? 아닐 수도 있다. No
	// 부모클래스에서 자식클래스로 넘어가는 건 아니된다.

	Knight k;
	// k.Move();	// 재정의한 Knight의 Move가 나온다.
	// MoveKnight(&k);	// 기사는 기사다? Yes
	MovePlayer(&k);	// 기사는 플레이어다? Yes	// Player쪽의 함수롤 실행

	return 0;
}