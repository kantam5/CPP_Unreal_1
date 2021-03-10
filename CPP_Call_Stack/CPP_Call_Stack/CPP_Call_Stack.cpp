#include <iostream>
using namespace std;

// 함수 선언을 먼저
void Func1();
void Func2(int hp, int mp); // 매개변수 이름이 달라도 된다.
void Func3(float);

void Func1()
{
    cout << "Func1" << endl;

    // push 1
    // push 2
    // call Func2   // Func2의 존재를 모른다
    Func2(1, 2);
}

void Func2(int a, int b)
{
    cout << "Func2" << endl;

    Func3(10.0f);

    Func3(11);
}

void Func3(float a)
{
    cout << "Func3" << endl;
}

int main()
{
    cout << "main" << endl;
    Func1();

    return 0;
}
