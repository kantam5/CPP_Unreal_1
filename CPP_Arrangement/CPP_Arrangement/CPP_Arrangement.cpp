#include <iostream>
using namespace std;

// 배열

struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defence = 0xDDDDDDDD;
};

int main()
{
	// TYPE 이름[개수];
	const int monsterCount = 10;
	// 배열의 크기는 상수여야 한다. vs 컴파일러 기준
	StatInfo monsters[monsterCount];

	// 여태껏 변수들의 [이름]은 바구니의 이름이었음
	
	// 배열은 [이름] 조금 다르게 동작한다.
	//StatInfo players[10];
	// players = monsters;
	// 그럼 배열의 이름은 뭐지?
	// 배열의 이름은 곧 배열의 시작 주소
	// 정확히는 시작 위치를 가리키는 TYPE* 포인터
	auto WhoAmI = monsters;

	// 주소[100,10,1] StatInfo[] StatInfo[] StatInfo[] ...
	// monster_0[주소]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10; 
	monster_0->defence = 1;

	// 포인터 덧셈은 진짜 주소에 1을 더하는게 아니라 TYPE 바구니 한개씩 이동이라는 의미
	// StatInfo[] 주소[200,20,2] StatInfo[] StatInfo[] ...
	// monster_1[주소]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// 포인터와 참조는 자유자재로 변환 가능하다.
	// StatInfo[] StatInfo[] 주소[] StatInfo[] ...
	// monster_2[주소]
	StatInfo& monster_2 = *(monsters + 2);	// 가리키는 것
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [주의] 이거는 완전 다른 의미다.
	// StatInfo[] StatInfo[] 주소[내용물] StatInfo[] ...
	// temp[내용물] 단순히 temp만 바뀜
	StatInfo temp;		// 그냥 데이터 그자체인 구조체
	temp = *(monsters + 2);
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	// 이를 조금 더 자동화
	for (int i = 0; i < 10; i++)
	{
		// 한바퀴 돌 때마다 monster라는 값의 수명이 리셋되서 같은 이름을 써도 괜찮음
		StatInfo& monster = *(monsters + i);
		monster.hp = (i + 1) * 100;
		monster.attack = (i + 1) * 10;
		monster.defence = i + 1;
	}

	// 근데 *(monsters + i) 너무 불편하고 가독성이 떨어진다.
	// -> 인덱스
	// 배열은 0번부터 시작, n번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[n]
	// *(monsters + i) = monsters[i]
	monsters[0].hp = 100;
	monsters[0].attack = 10;
	monsters[0].defence = 1;

	int hp = monsters[0].hp;
	for (int i = 0; i < 10; i++)
	{
		monsters[1].hp = (i + 1) * 100;;
		monsters[1].attack = (i + 1) * 10;
		monsters[1].defence = i + 1;
	}

	// 배열 초기화 문법 몇가지
	int numbers[5] = {};	// 기본값 0으로 초기화
	int numbers1[10] = { 1, 2, 3, 4, 5 };	// 설정한 값은 설정한값으로 나머진 0
	int numbers2[] = { 1, 2, 3, 4, 5, 6, 7, 8 };	// 설정한 개수 만큼만 배열 설정
	char helloStr[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
	cout << helloStr << endl;

	// 배열 요약
	// 1) 선언한다
	// 2) 인덱스로 접근하여 사용

	return 0;
}
