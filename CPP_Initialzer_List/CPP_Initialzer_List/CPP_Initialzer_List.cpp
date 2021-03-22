#include <iostream>
using namespace std;

// 초기화 리스트

// 결국에는 멤버 변수를 어떻게 초기화 할지

// 초기화 왜 해야할까?
// - 버그 예방에 중요
// - 포인터 등 주소값이 연루되어 있는 경우

// 초기화 방법
// - 생성자 내에서
// - 초기화 리스트
// - C++ 11 문법

// 초기화리스트
// - 일단 상속 관계에서 원하는 부모 생성자 호출할 때 필요하다.
// - 생성자 내에서 초기화 vs 초기화 리스트
// -- 일반 변수는 별 차이 없음
// -- 멤버 타입이 클래스인 경우 차이가 난다.
// -- 정의함과 동시에 초기화가 필요한 경우 (참조 타입, const 타입)


class Inventory
{
public:
    Inventory() { cout << "Inventory()" << endl; }
    Inventory(int size) { cout << "Inventory(int size)" << endl; _size = size; }
    ~Inventory() { cout << "~Inventory()" << endl; }

public:
    int _size = 10;
};

class Player
{
public:
    Player() { }
    Player(int id) { }

public:
};

// Is_A (Knight Is-A Player?) OK -> 상속관계
// Has_A (Knight Has_A Inventory?) NO -> 포함관계

class Knight : public Player
{
public:
    Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100)  // 초기화 리스트
        /*
        선처리 영역
        Inventory()
        */
    {
        _hp = 100;
        // Inventory를 생성하면 선처리와 여기 2개가 생성되고 선처리의 Inventory가 바로 소멸됨 
        // _inventory = Inventory(20);
    }


public:
    int _hp;    // 초기화 전엔 쓰레기값 (cccccccc)
    Inventory _inventory;   // 포함관계

    int& _hpRef;    // 만들어짐과 동시에 초기화 해야하므로 초기화 리스트로
    // int& _hpRef = _hp;
    const int _hpConst;
    // const int _hpConst = 100;
};


int main()
{
    Knight k;

    cout << k._hp << endl;

    if (k._hp < 0)
    {
        cout << "Knight is Dead" << endl;
    }


    return 0;
}
