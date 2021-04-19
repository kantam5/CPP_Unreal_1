#include <iostream>
using  namespace std;

// nullptr

class Knight
{
public:
    void Test()
    {

    }
};

Knight* FindKnight()
{
    // TODO
    return nullptr;
}

void Test(int a)
{
    cout << "Test(int)" << endl;
}
void Test(void* ptr)
{
    cout << "Test(*)" << endl;
}


// nullptr 구현
const
class
{
public:
    // 그 어던 타입의 포인터라도 치환 가능
    template<typename T>
    operator T* () const
    {
        return 0;
    }
    // 그 어떤 타입의 멤버 포인터가와도 치환 가능
    template<typename C, typename T>
    operator T C::* () const
    {
        return 0;
    }
private:
    void operator&() const; // 주소값 &을 막는다.
} _NullPtr;


int main()
{
    int* ptr = _NullPtr;     // 0이 들어가 있음
    // int* ptr = NULL;     // NULL은 사실상 0을 넣은것과 다를바 없다.

    Test(0);
    Test(NULL);             // 결국 int버전이 호출된다.
    Test(_NullPtr);          // 포인터 버전이 호출된다.
    // 1) 오동작 방지
    
    // 2) 가독성
    auto knight = FindKnight();
    if (knight == _NullPtr)
    {


    }

    void(Knight:: * memFunc)();
    memFunc = &Knight::Test;

    if (memFunc == _NullPtr)
    {

    }

    nullptr_t whoami = nullptr;

    return 0;
}
