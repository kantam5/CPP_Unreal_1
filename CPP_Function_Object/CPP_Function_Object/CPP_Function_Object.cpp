#include <iostream>
using namespace std;

// 함수 객체 Fuctor
// 함수처럼 동작하는 객체


void HelloWorld()
{
    cout << "Hello World" << endl;
}

class Knight
{
public:
    void AddHp(int addHp)
    {
        _hp += addHp;
    }

public:
    int _hp = 100;
};

// 함수 객체
class Fuctor
{
public:
    void operator()()
    {
        cout << "Fuctor Test" << endl;
        cout << _value << endl;
    }
    bool operator()(int num)
    {
        cout << "Fuctor Test" << endl;
        _value += num;
        cout << _value << endl;

        return true;
    }

public:
    int _value = 0;
};

class MoveTask
{
public:
    void operator()()
    {
        cout << "플레이어 이동" << endl;
    }

public:
    int _playerId;
    int _posX;
    int _posY;
};

int main()
{
    // 함수 포인터 선언과 사용
    // 동작을 넘겨줄 때 유용하다. 
    void (*pfunc)(void);
    pfunc = HelloWorld;
    (*pfunc)();
    // 함수포인터의 단점
    // 1) 완전히 동일한 인자, 반환값만 사용가능, 시그니쳐가 안 맞으면 사용 불가능
    // 2) 상태를 가질 수 없다. 함수에 저장되는 값을 가질 수 없다. 객체의 멤버변수느낌

    // [함수처럼 동작]하는 객체
    // () 연산자 오버로딩
    Fuctor functor;
    functor();   // 객체에 ()를 붙이는 느낌
    // 상태값도 가질 수 있게 되었다.
    bool ret = functor(11);

    // mmo에서 함수 객체를 사용하는 예시
    // 클라 <-> 서버
    // 서버: 클라가 보내준 네트워크 패킷을 받아서 처리
    // ex) 클라: 나 (5, 5)로 이동시켜줘
    MoveTask task;
    task._playerId = 100;
    task._posX = 5;
    task._posY = 5;

    // 위의 생성을 먼저하고 나중에 서버의 여유가 될 때 위의 일을 실행한다. 
    task();



    return 0;
}
