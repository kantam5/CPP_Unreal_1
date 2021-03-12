#include <iostream>
using namespace std;

// 1) 주소 연산자 (&)
// 2) 산술 연산자 (+ -)
// 3) 간접 연산자
// 4) 간접 멤버 연산자

struct Player
{
    int hp;     // + 0
    int damage; // + 4
};

int main()
{
    int number = 1;
    // 1) 주소 연산자 (&)
    // - 해당 변수의 주소를 알려주세요
    // - 더 정확히 말하면 해당 변수 타입에 따라서 TYPE* 변환
    int* pointer = &number;

    // 2) 산술 연산자 (+ -)
    number += 1;    // number에 1을 더한다
    //pointer = pointer + 1;
    //pointer++;
    //++pointer;
    // int*
    // - * : 포인터 타입이네! (8바이트) 주소를 담는 바구니다
    // - int : 주소를 따라가보면 4바이트 정수형 바구니가 있다고 가정해라!
    // [1] 포인터에서 + - 등 산술 연산을 하면 
    // 정말 그 숫자를 더하고 뺴라는 의미가 아니라
    // 한번에 TYPE의 크기만큼을 이동한다. 
    // 다음 / 이전 바구니로 이동하고 싶다 << [바구니 단위]의 이동으로
    // 즉 1을 더하면 바구니 1개 이동시켜라
    // 3을 더하면 바구니 3개 이동시켜라
    // 배열을 이용할 때 주로 사용한다. 
    pointer += 2;      // pointer = &numver + 4(TYPE의 크기) * 2

    // 3) 간접 연산자 (*)
    // - 포탈을 타고 해당 주소로 이동
    *pointer = 3; // == number = 3

    // 4) 간접 멤버 연산자 (->)
    // *(포탈) 과 .(구조체의 특정 멤버를 다룰 떄, 사실상 그냥 덧셈)을 합한 것
    // ->  ==  *을 한다음 .을 처리하는 것
    Player player;
    player.hp = 100;
    player.hp = 10;

    Player* playerPtr = &player;
    (*playerPtr).hp = 200;
    (*playerPtr).damage = 200;  // playerPtr의 주소에서 +4의 위치
    // 위와 아래 똑같음
    playerPtr->hp = 400;
    playerPtr->damage = 400;

    return 0;
}