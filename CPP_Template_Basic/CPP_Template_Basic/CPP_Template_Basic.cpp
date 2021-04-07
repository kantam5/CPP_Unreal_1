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




// -----------------------------------------------------
// 클래스 템플릿
// 무조건 typename을 붙여야 하는 것은 아니다
// 유동적으로 배열의 크기를 늘려주게 해보자
// -> SIZE 기본값 설정가능
// template<>안에 들어가는건 골라줘야하는 일종의 목록이라 볼수 있다.
template<typename T, int SIZE = 10>
class RandomBox
{
public:
    T GetRandomData()
    {
        int idx = rand() % SIZE;
        return _data[idx];
    }
public:
    T _data[SIZE];
};

// 템플릿 특수화  double버전이라면 밑의 템플릿이 호출
template<int SIZE>
class RandomBox<double, SIZE>
{
public:
    double GetRandomData()
    {
        cout << "RandomBox() double" << endl;
        int idx = rand() % SIZE;
        return _data[idx];
    }
public:
    double _data[SIZE];
};

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
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

    cout << "-----------------------------------------" << endl;


    RandomBox<int, 10> rb1;
    for (int i = 0; i < 10; i++)
    {
        rb1._data[i] = i;
    }
    int value1 = rb1.GetRandomData();
    cout << value1 << endl;

    RandomBox<int, 20> rb2;
    for (int i = 0; i < 20; i++)
    {
        rb2._data[i] = i + 0.5f;
    }
    int value2 = rb2.GetRandomData();
    cout << value2 << endl;

    // 템플릿 특수화
    RandomBox<double, 20> rb3;
    for (int i = 0; i < 20; i++)
    {
        rb3._data[i] = i + 0.5;
    }
    double value3 = rb3.GetRandomData();
    cout << value3 << endl;

    return 0;
}
