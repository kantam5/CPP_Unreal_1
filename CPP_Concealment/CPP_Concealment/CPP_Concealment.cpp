#include <iostream>
using namespace std;

// 은닉성 (Data Hiding) = 캡슐화 (Encapsulatin)
// 몰라도 되는 것은 깔끔하게 숨기겠다.
// 이유
// 1) 정말 위험하고 건드리면 안되는 경우
// 2) 다른 경로로 접근하길 원하는 경우

// 자동차
// - 핸들
// - 페달
// - 엔진
// - 문
// - 각종 전기선

// 일반 구매자 입장에서 사용하는 것?
// - 핸들
// - 페달
// - 문
// - 몰라도 되는 부분(오히려 건드리면 큰일남)
// -- 엔진, 각종 전기선

// public(공개적) protected(보호받는) private(개인적인)
// - public : 누구한테나 공개, 실컷 사용하세요
// - protected : 나의 자손들한테만 허락 외부 안됨
// - private : 나만 사용할 꺼임 class Car 내부에서만 사용가능

class Car
{
public: // (멤버) 접근 지정자
    void MoveHandle() {}
    void PushPadal() {}
    void OpenDoor() {}
    void TurnKey()
    {
        RunEngine();
    }
  
protected:
    void RunEngine() {}

private:
    void DisassembleCar() {}
    void ConnerctCircuit() {}

public:
    
};

// 상속 접근 지정자 : 다음 세대한테 부모님의 우이신을 어떻게 물려줄지? 
// 부모님한테 물려받은 유산을 꼭 나의 자손들한테도 똑같이 물려줘야 하진 않음
// - public : 공개적 상속. 부모님의 유산 설계 그대로 (public -> public, protected -> protected)
// - protected : 보호받은 상속. 내 자존들한테만 물려줄꺼야 (public -> protected, protected -> protected)
// - private : 개인적인 상속. 나까지만 잘 쓰고 자존들한테는 아예 안 물려 줄꺼야 (publiic -> private, protected -> private)
class SuperCar : private Car // 상속 접근 지정자
{
public:
    void PushRemoteController()
    {
        RunEngine();
    }
};

class TestSuperCar : SuperCar   // 상속 접근 지정자 없으면 private
{
public:
    void Test()
    {
        // DisassembleCar();   // 엑세스 할 수 없습니다.
    }
};

// 캡슐화
// 연관된 데이터와 함수를 논리적으로 묶어놓은 것
class Berserker
{
public:
    int GetHp()
    {
        return _hp;
    }
    void SetHp(int hp)
    {
        _hp = hp;
        if (_hp <= 50)
            SetBerserkerMode();
    }

private:
    // 사양 : 체력이 50 이하로 떨어지면 버서커 모드 발동
    void SetBerserkerMode()
    {
        cout << "매우 강해짐!" << endl;
    }

private:
    int _hp = 100;
};

int main()
{
    Car car;
    // 건드리면 안되는 것도 건드려버린다.
    //car.DisassembleCar();       // 엑세스 할 수 없습니다.

    TestSuperCar car2;
    

    Berserker b;
    b.SetHp(20);



    return 0;
}