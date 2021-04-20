#include <iostream>
using namespace std;

// enum class

// unscoped enum
// 범위가 전역으로 퍼진다 {}무시
enum PT_Type
{
    PT_Knight,
    PT_Archer,
    PT_Mage
};

enum MT_Type
{
    MT_None
};

// 범위가 {} 한정
enum class ObjectType
{
    Player,
    Monster,
    Projectile
};

int main()
{
    // enum class (scoped enum)
    // enum과 장단점이 있다
    // 1) 이름 공간 관리에 이점
    // 2) 암묵적인 변환 금지

    double value = PT_Knight;   // 그냥 0임

    double value2 = static_cast<double>(ObjectType::Player);    // 암묵적인 변환 안됨


    return 0;
}
