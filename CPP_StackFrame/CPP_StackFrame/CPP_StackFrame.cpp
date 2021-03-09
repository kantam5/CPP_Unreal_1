#include <iostream>
using namespace std;

// F5 디버깅 모드 실행 후 break point에서 멈춤 그 후 다시 F5를 누르면 다음 break point에서 멈춤
// F10 프로시저(함수)단위로 실행
// F11 한 줄씩 코드 실행

/*
input으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다.

반환타입 함수이름(매개변수)
{
    내용

    return
}
*/

void PrintHellowWorld()
{
    cout << "Hellow World" << endl;
}

void PrintNumber(int number)
{
    cout << number << endl;
}

int MultiplyBy2(int number)
{
    return 2 * number;
}

int MultiplyBy(int a, int b)
{
    int c = a * b;
    return c;
}

int main()
{
    int a = 5;
    int b = 2;
    int result = MultiplyBy(a, b);

    PrintNumber(result);


    return 0;
}