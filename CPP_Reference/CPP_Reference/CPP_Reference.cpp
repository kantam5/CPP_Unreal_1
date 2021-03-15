#include <iostream>
using namespace std;

// 참조 기초
struct StatInfo
{
    int hp;         // +0
    int attack;     // +4
    int defence;    // +8
};

void CreateMonster(StatInfo* info)
{
    info->hp = 100;
    info->attack = 8;
    info->defence = 5;
}

// 주소가 아닌 info라는 매개변수를 복사하여 복사한 것에 넣는 것. 원본은 안 바뀐다.
void CreateMonster(StatInfo info) 
{
    info.hp = 100;
    info.attack = 8;
    info.defence = 5;
}

// 값을 수정하지 않는다면, 양쪽 다 일단 문제 없음
// 1) 값 전달 방식
void PrintInfoByCopy(StatInfo info)
{
    cout << "-----------------------" << endl;
    cout << "HP;  " << info.hp << endl;
    cout << "ATK: " << info.attack << endl;
    cout << "DEF: " << info.defence << endl;
    cout << "-----------------------" << endl;
}

// 2) 주소 전달 방식
void PrintInfoByPtr(StatInfo* info)
{
    cout << "-----------------------" << endl;
    cout << "HP;  " << info->hp << endl;
    cout << "ATK: " << info->attack << endl;
    cout << "DEF: " << info->defence << endl;
    cout << "-----------------------" << endl;
}

// StatInfo 구조체가 1000바이트 짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사되는
// - (주소 전달) StatInfo*는 8바이트
// - (참조 전달) StatInfo&는 8바이트

void PrintInfoByRef(StatInfo& info)
{
    cout << "-----------------------" << endl;
    cout << "HP;  " << info.hp << endl;
    cout << "ATK: " << info.attack << endl;
    cout << "DEF: " << info.defence << endl;
    cout << "-----------------------" << endl;
}

int main()
{
    int number = 1;
    int* pointer = &number;
    *pointer = 2;
    
    // 3) 참조 전달 방식
    // 로우레벨(어셈블리) 관점에서 실제 작용 방식은 int*와 똑같음
    // C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것
    // 앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면
    // 실제 number 바구니(진퉁에다가) 그 값을 꺼내거나 넣으면 됨!
    // 실제 실험해보면 포인터랑 똑같다.
    // 근데 귀찮게 또 다른 이름을 짓는 이유는?
    // 값 전달처럼 편리하게 사용하고!
    // 주소 전달처럼 주소값을 이용해 진퉁을 건드리는
    // 일석 이조의 방식
    int& reference = number;
    reference = 3;      // number에 3이 들어간다.

    StatInfo info;
    CreateMonster(&info);

    PrintInfoByCopy(info);
    PrintInfoByPtr(&info);
    PrintInfoByRef(info);

    return 0;
}