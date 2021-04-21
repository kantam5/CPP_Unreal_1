#include <iostream>
using namespace std;

// 오른값 참조 , std::move

class Pet
{

};

class Knight
{
public:
    void PrintInfo() const
    {

    }
    Knight()
    {
        cout << "Knight()" << endl;
    }
    // 복사 생성자
    Knight(const Knight& knight)
    {
        cout << "const Knight&" << endl;
    }
    // 이동 생성자
    Knight(Knight&& knight)
    {

    }
    ~Knight()
    {
        if (_pet)
            delete _pet;
    }
    void operator=(const Knight& knight)
    {
        cout << "operator=(const Knight& knight)" << endl;

        _hp = knight._hp;
        if (knight._pet)
            _pet = new Pet(*knight._pet);
    }
    // 이동 대입 연산자
    void operator=(Knight&& knight) noexcept
    {
        cout << "operator=(Knight&& knight)" << endl;

        _hp = knight._hp;
        // 굳이 깊은 복사까지 필요없고 받은 pet을 바로 쓰면 된다.
        // 얕은 복사
        _pet = knight._pet;

        knight._pet = nullptr;
    }

public:
    int _hp = 100;
    Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight) {  }
void TestKnight_LValueRef(Knight& knight) {  }
void TestKnight_ConstLValueRef(const Knight& knight) {  }
void TestKnight_RValueRef(Knight&& knight) { knight._hp = 200; }     // &&오른값 참조
// 원본객체를 넘겨줄 텐데 읽고 쓰기도 가능한데 함수가 호출한뒤 활용하지 안을테니
// 마음대로 해도됨 -> 이동 대상 -> 왜냐면 넘겨준 원본은 필요없는 오른값이기에

int main()
{
    // 왼값(lvalue) vs 오른값(rvalue)
    // - lvalue : 단일식을 넘어서 계속 지속되는 계체
    // - rvalue : lavalue가 아닌 나머지 (임시 값, 열거형, 람다, i++ 등)

    // int a = 3;
    // a는 왼값, 3은 오른값

    Knight k1;

    TestKnight_Copy(k1);
    // TestKnight_LValueRef(k1);
    TestKnight_ConstLValueRef(Knight());     // 딱한번 호출되고 나면 없어지는 Knight()
    // const가 붙어지면 오른값이라도 받아준다.

    TestKnight_RValueRef(Knight());           // 왼값은 불가능 

    TestKnight_RValueRef(static_cast<Knight&&>(k1));
    // 원본을 고칠 수도 있음

    Knight k2;
    k2._pet = new Pet();
    k2._hp = 1000;

    // 원본은 날려도 된다는 힌트를 준다/
    Knight k3;
    k3 = static_cast<Knight&&>(k2);

    k3 = move(k2);      // k3 = static_cast<Knight&&>(k2); 와 같다.
    // 오른값 참조로 캐스팅
    // std::move의 본래 이름 후보 중 하나가 rvalue_cast

    // 세상에 딱 하나만 존재해야 하는 포인터
    std::unique_ptr<Knight> uptr = std::make_unique<Knight>();
    // std::unique_ptr<Knight> uptr2 = uptr; 안됨
    std::unique_ptr<Knight> uptr2 = std::move(uptr);    // 소유권을 넘겨준다는 느낌

    return 0;
}
