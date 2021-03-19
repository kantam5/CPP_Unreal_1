#include <iostream>
using namespace std;

// 데이터 + 가공(로직 혹은 동작)

// 객체지향의 주인공은 객체
// 객체란 게임속에 존재하는 모든 오브젝트
// 플레이어, 몬스터, GameRoom 등등

// [생성자][Constructor][소멸자]
// 클래스에 소속된 함수들 중
// 특별한 2종 시작과 끝을 알리는 함수들
// 생성자와 소멸자 
// - 시작[탄생] -> 생성자 여러개 가능
// - 끝[소멸] -> 소멸자 오직 1개만 가능

// [암시적 생성자]
// 생성자를 명시적으로 만들지 않으면
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐
// -> 그러나 우리가 명시적으로 아무 생성자를 하나 만들면
// 자동으로 만들어지던 기본 생성자는 더 이상 만들어 지지않음 

// knight를 살펴보자
// - 속성(데이터) hp, attack, y, x
// - 기능(동작) Move, Attack, Die
// - 설계도
class knight
{
public:
    // 멤버 함수
    
    // [1] 기본 생성자 (인자가 없음)
    knight()
    {
        cout << "knight() 기본생성자 호출" << endl;

        _hp = 100;
        _attack = 10;
        _posY = 0;
        _posX = 0;
    }
    // [2] 복사 생성자  자기 자신의 클래스 참조 타입을 인자로 받음
    // 생성할 때 어떤 객체를 복사하여 만들겠다. 
    // 일반적으로 똑같은 데이터를 지닌 객체가 생성되길 기대한다.
    knight(const knight& knight)
    {
        _hp = knight._hp;
        _attack = knight._attack;
        _posY = knight._posY;
        _posX = knight._posX;
    }
    // [3] 기타 생성자
    // 기타 생성자 중에서 인자를 1개만 받는 기타 생성자를 
    // 별도로 타입 변환 생성자라고 부르기도 함
    knight(int hp, int attack, int y, int x)
    {
        _hp = hp;
        _attack = attack;
        _posY = y;
        _posX = x;
    }
    // 타입 변환 생성자
    // 명시적인 용도로만 사용할 거라면 앞에 explicit를 붙인다.
    explicit knight(int hp)
    {
        cout << "knight(int) 생성자 호출" << endl;
        _hp = hp;
        _attack = 10;
        _posY = 0;
        _posX = 0;
    }

    // [4] 소멸자 ~로 표시
    ~knight()
    {
        cout << "~knight() 소멸자 호출" << endl;
    }

    // - 멤버 변수에 접근 가능
    void Move(int y, int x);
    void Attack();
    void Die()
    {
        this->_hp = 0;
        _hp = 0;    // this->_hp = 1; 와 똑같이 동작한다. 
        cout << "Die" << endl;
    }
    void HellowKinght(knight k)
    {
        cout << "Hellow Knight " << k._hp << endl;
    }

public:
    // 멤버 변수
    int _hp;
    int _attack;
    int _posY;
    int _posX;
};

void knight::Move(int y, int x)
{
    _posY = y;
    _posX = x;
    cout << "Move" << endl;
}

void knight::Attack()
{
    cout << "Attack : " << _attack << endl;
}

void Move(knight* knight, int y, int x)
{
    knight->_posY = y;
    knight->_posX = x;
}

// instantiate 객체를 만든다

int main()
{
    knight k1(100);
    k1._attack = 10;
    k1._posY = 0;
    k1._posX = 0;

    knight k2(k1);
    knight k3 = k1; // 복사 생성자로 만들어짐

    knight k4;      // 기본 생성자로 만드어진 다음
    k4 = k1;        // 그 다음 복사


    knight k5(1, 1, 1, 1);

    k1.Move(1, 1);
    k1.Attack();
    k1.Die();

    // 암시적 형변환 -> 컴파일러가 알아서 바꿔치기
    int num = 1;
    float t = num;  // 실수형 바구니에 정수형을 넣으면 1.0으로 형변환
    float p = (float)num;   // 우리가 명시적으로 변환

    knight k6;
    k6 = (knight)1;     // 타입 변환 생성자가 호출된다 knight(int hp)
    // explicit를 붙이면 error 앞에 명시적으로 (kngiht)붙이면 된다.

    k6.HellowKinght((knight)1); // 컴파일러가 암시적으로 형변환 시킴
    // -> 실질적으로 1을 넣었을 때 knight k가 실행되면서
    // -> 형변환 생성자(knight(int hp))가 호출되어 knight가 생성되어 들어간다.
    // explicit를 붙이면 error


    return 0;
}
