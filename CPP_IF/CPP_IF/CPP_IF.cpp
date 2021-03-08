#include <iostream>
using namespace std;

// 분기문
// 데이터를 메모리에 할당하고 가공하고 방법에 대해 알아봄
// 가공한 데이터를 이용해서 무엇인가를 하고 싶다면?

int main()
{
	int hp = 100;	// 몬스터 hp
	int damage = 100;	// 플레이어 데미지

	hp -= damage;
	bool isDead = (hp <= 0);

	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;

	int input = ROCK;

	// 몬스터가 죽었으면 경험치 추가
	// 어셈블리에서는 CMP, JMP

	if (isDead) {
		cout << "몬스터를 처치했습니다." << endl;
	}
	else if (hp <= 20) {
		cout << "몬스터가 도망가고 있습니다." << endl;
	}
	else {
		cout << "몬스터가 반격했습니다." << endl;
	}

	if (input == ROCK) {
		cout << "바위를 냈습니다." << endl;
	}
	else if (input == PAPER) {
		cout << "보를 냈습니다." << endl;
	}
	else if (input == SCISSORS) {
		cout << "가위를 냈습니다." << endl;
	}
	else {
		cout << "뭘 낸겁니까?" << endl;
	}

	// switch - case
	// 정수 개열만 넣을 수 있다. 
	// flaot 같은건 안된다. 
	switch (input) {
	case ROCK:
		cout << "바위를 냈습니다." << endl;
		break;
	case PAPER:
		cout << "보를 냈습니다." << endl;
		break;
	case SCISSORS:
		cout << "가위를 냈습니다." << endl;
		break;
	default:
		cout << "뭘 낸겁니까?" << endl;
		break;
	}
}
