#include <iostream>
using namespace std;

// 객체지향 마무리

// 1) sturct vs class
// - C++ 에세ㅓ는 종이한장 차이
// - sturuct에서는 기본 접근 지정자가 public
// - class 는 private이다
// 왜 이렇게 했냐 c++는 c에서 파생되었기 때문에 호환성을 지키기 위함
// -> struct는 그냥 구조체 (데이터 묶음)을 표헌하는 용도로 쓰고
// -> class는 객체 지향 프로그래밍의 특징을 나타내는 용도로 쓰자
struct TestStruct
{
    int _a;
    int _b;
};

class TestClass
{
    
    int _a;
    int _b;
};

// 2) static 변수, static 함수 (static = 정적, 고정된)
// 그 클래스의 대표 변수와 함수? 
// 하나씩만 존재
// 스태틱 함수는 같은 스태틱 변수만 건드릴 수 있다.
class Marine
{
public:
    void TakeDamage(int damage)
    {
        _hp -= damage;
    }
    // 전역함수를 만들어 준것 마냥 독립적으로 행동
    // 설계도 상으로만 마린안에 있는 전역함수
    static void SetAttack()
    {
        s_attack = 100;
    }


public:
    // 특정 마린 객체에 종속적
    int _hp;

    // 마린이라는 '클래스'자체와 연관
    static int s_attack; // 설계도 상으로만 존재
};

// static 변수는 어떤 메모리?
// 초기화 하면 .data
// 초기화 안하면 .bss
int Marine::s_attack = 0;   // 누구에게나 동일한 값

class Player
{
public:
    int _id;
};

int GenerateId()
{
    // 생명주기 : 프로그램 시작/종료 [메모리에 항상 올라가 있음] 
    // 가시범위 : 사용은 영역 내부에서만

    // 정적 지역 객체 정적이라 데이터 영역에 올라간다. 데이터 유지
    static int s_id = 1;

    return s_id++;
}

int main()
{
    TestStruct ts;
    ts._a = 1;

    TestClass tc;

    Marine m1;
    m1._hp = 40;
    m1.TakeDamage(10);

    Marine::s_attack = 6;

    Marine m2;
    m2._hp = 40;
    m2.TakeDamage(5);
    // m2.s_attack = 6;

    // 마린 공격력 업그레이드 완료 (academy에서 업그레이드 끝)
    Marine::s_attack = 7;
    Marine::SetAttack();

    // static은 함수내부에 만들어도 stack이 아닌 data영역에 올라간다.
    static int id = 10;
    int a = id;

    cout << GenerateId() << endl;
    cout << GenerateId() << endl;
    cout << GenerateId() << endl;
    cout << GenerateId() << endl;
    cout << GenerateId() << endl;


    return 0;
}
