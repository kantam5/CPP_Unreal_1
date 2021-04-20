#include <iostream>
using namespace std;

// delete (삭제된 함수)

class Knight
{
public:

// 구닥다리 문법
private:
    // 정의되지 않은 비공개 함수
    // 명시적으로 사용을 안하겠다고 꺼놓은 느낌
    void operator=(const Knight& k) = delete;

    // friend class Admin; // Admin한테는 나의 private에 접근하는걸 허락하겠다.

public:
    int _hp = 100;
};

class Admin
{
public:
    void CopyKnight(const Knight& k)
    {
        Knight k1;
        k1 = k;
    }
};

int main()
{
    Knight k1;

    Knight k2;

    // 복사 연산자
    k1 = k2;

    Admin admin;
    admin.CopyKnight(k2);



    return 0;
}
