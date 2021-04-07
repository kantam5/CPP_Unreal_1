#include <iostream>
using namespace std;

// 함수 포인터 2

// typedef의 진실
// typedef 왼쪽 오른쪽 -> 오른쪽 (커스텀 타입)
// 정확히는 왼쪽 / 오른쪽 기준이 아니라
// [선언 문법]에서 typedf를 앞에다 붙이는 쪽

class Knight
{
public:
    // 멤버 함수
    int GetHp(int a, int b)
    {
        cout << "GetHp()" << endl;
        return _hp;
    }
public:
    int _hp = 100;
};

typedef int INTEGER;
typedef int* POINTER;
// typedef int FNC(int, int);  // typedef를 붙이면 인자는 아무것도 없고 반환은 int인 함수를 FNC라 부른다는 뜻
typedef int ARRAY[20];

typedef int (*PFNC)(int, int);      // 정적/전역 함수 포인터

typedef int (Knight::*PMFNC)(int, int); // 멤버함수 포인터


int Test(int a, int b)
{
    cout << "Test" << endl;
    return a + b;
}

int t(int a, int b)
{
    cout << "t" << endl;
    return a + b;
}


int main()
{
    // 함수 포인터
    // 1) 포인터 *
    // 2) 변수의 이름 fn
    // 3) 타입 함수(인자로 int 2개를 받고, int 1개를 반환)
    // int (*fn)(int, int);

    // FNC t;  // 메모리가 올라가는 게아니라 함수라는게 존재하는데 그 함수를 타고가면 구현부가 있다.
    t(1, 2);

    // typedef int(FNC_TYPE)(int, int);
    // FNC_TYPE* fn;
    PFNC fn;

    fn = &Test;  // &생략가능 (c언어와의 호환성 때문)
    fn(1, 2);
    (*fn)(1, 2);



    // 위 문법으로 [전역 함수 / 정적 함수]만 담을 수 있다. (호출 규약이 동일한 애들)
    // fn = &Knight::GetHp; 안됨
    
    Knight k1;
    k1.GetHp(1, 2);
    
    PMFNC mfn;

    mfn = &Knight::GetHp; // &생략 불가능
    // 바로 사용 불가능 어떤 객체를 대상으로 사용해야됨
    (k1.*mfn)(1, 2);

    Knight* k2 = new Knight();

    (*k2.*mfn)(1, 2);       // 포인터면 포인터의 실체로
    (k2->*mfn)(1, 2);       // same

    delete k2;

    return 0;
}
