#include <iostream>
using namespace std;

// 템플릿 기초

class Knight
{
public:

public:
    int _hp = 100;
};

template<typename T>    // 타입은 나중에 정해줄께
// template<class T>       // same
void Print(T a)
{
    cout << a << endl;
}

// 템플릿 특수화  특정타입에만 다른 규칙을 따르고 싶을 때
template<>
void Print(Knight a)
{
    cout << "Knight-----" << endl;
    cout << a._hp << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
    cout << a << " " << b << endl;
}

template<typename T>
T Add(T a, T b)
{
    return a + b;
}


// 연산자 오버로딩 (전역함수 버전)   새로운 규칙 추가
ostream& operator<<(ostream& os, const Knight& k)
{
    os << k._hp;
    return os;
}




int main()
{
    // 템플릿 : 함수나 클래스를 찍어내는 틀
    // 1) 함수 템플릿
    // 2) 클래스 템플릿

    Print(11);          // 사용할 때마다 컴파일러가 각기 다른 버전을 생성시켜줌
    Print<int>(11.1f);     // <>로 무조건 int로
    Print(11.1f);
    Print(11.11);
    Print("Hello World");

    Print(11, "가나");

    int reuslt = Add(1, 2);
    float result2 = Add<int>(2.1f, 2.1f);


    Knight k1;
    Print(k1);


    return 0;
}
