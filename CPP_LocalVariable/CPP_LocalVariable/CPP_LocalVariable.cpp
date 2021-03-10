#include <iostream>
using namespace std;

// 전역 변수
// 참고) 초기화 여부, const 등 .rodata, .data, .bss
int globalValue = 0;

void Test()
{
    cout << "전역변수의 값은 : " << globalValue << endl;
    globalValue++;
}

void increaseHp(int hp)
{
    hp++;
}

// [매개변수][RET][지역변수] (스택 프레임의 대략적 모습)
// [매개변수][RET][지역변수 hp=1] -> [매개변수 hp=1][RET][지역변수]
int main()
{
    int hp = 1;

    cout << "increase 호출 전 " << hp << endl;
    increaseHp(hp); // = increaseHp(1) 값 전달 그저 값을 복사하여 넘긴다.

    cout << "increase 호출 후 " << hp << endl;

    return 0;
}
