#include <iostream>
using namespace std;

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
    return a * b;
}

int main()
{
    PrintHellowWorld();
    PrintNumber(3);
    cout << MultiplyBy2(2) << endl;
    PrintNumber(MultiplyBy(2, 9));
    return 0;
}