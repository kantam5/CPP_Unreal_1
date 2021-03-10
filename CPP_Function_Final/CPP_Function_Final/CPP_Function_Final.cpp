#include <iostream>
using namespace std;

// 오버로딩 (중복 정의) : 함수 이름의 재사용
// - 매개변수 갯수가 다르거나 타입이 다를 때 (순서가 다른걸 포함)
// - 반환형식만 다르면 안 된다.
int Add(int a, int b)
{
    int result = a + b;
    return result;
}
float Add(float a, float b)
{
    float result = a + b;
    return result;
}

// 기본 인자값
// - 길드 아이디가 있을 수도 있고 없을 수도 있음
// - 없으면 0으로 
// - 기본 인자값이 있는 인자는 꼭 마지막에 위치해야 된다.
void SetPlayerInfo(int hp, int mp, int attack, int gulidId = 0, int castleId = 0)
{

}

// 스택 오버플로우
// - 너무 많은 함수를 호출하면 발생 
int Factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * Factorial(n - 1);
    
}

int main()
{
    float result = Add(1.5f, 2.1f);
    cout << result << endl;

    SetPlayerInfo(100, 40, 10, 0);
    SetPlayerInfo(110, 20, 11); // 기본적으로 0값을 넣어준다.

    cout << Factorial(100) << endl;

    return 0;
}