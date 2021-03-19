#include <iostream>
using namespace std;

// 데이터 + 가공(로직 혹은 동작)

// 객체지향의 주인공은 객체
// 객체란 게임속에 존재하는 모든 오브젝트
// 플레이어, 몬스터, GameRoom 등등

// knight를 살펴보자
// - 속성(데이터) hp, attack, y, x
// - 기능(동작) Move, Attack, Die
// - 설계도
class knight
{
public:
    // 멤버 함수
    // - 멤버 변수에 접근 가능
    void Move(int y, int x);
    void Attack();
    void Die()
    {
        hp = 0;
        cout << "Die" << endl;
    }
public:
    // 멤버 변수
    int hp;
    int attack;
    int posY;
    int posX;
};

void knight::Move(int y, int x)
{
    posY = y;
    posX = x;
    cout << "Move" << endl;
}

void knight::Attack()
{
    cout << "Attack : " << attack << endl;
}

void Move(knight* knight, int y, int x)
{
    knight->posY = y;
    knight->posX = x;
}

// instantiate 객체를 만든다

int main()
{
    knight k1;
    k1.hp = 100;
    k1.attack = 10;
    k1.posY = 0;
    k1.posX = 0;

    knight k2;
    k2.hp = 80;
    k2.attack = 5;
    k2.posY = 1;
    k2.posX = 1;

    Move(&k1, 2, 2);

    k1.Move(1, 1);
    k1.Attack();
    k1.Die();


    return 0;
}
