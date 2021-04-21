#include <iostream>
using namespace std;

// 전달 참조
// template과 auto 같은 추론이 필요한 경우 이용
// 그냥 forward사용해 

class Knight
{
public:
    Knight()
    {
        cout << "기본 생성자" << endl;
    }
    Knight(const Knight&)
    {
        cout << "복사 생성자" << endl;
    }
    Knight(Knight&&) noexcept
    {
        cout << "이동 생성자" << endl;
    }
};

void Test_RValueRef(Knight&& k)     // 오른값 참조
{

}

void Test_Copy(Knight k)
{

}

// const가 붙으면 전달 참조로 동작 안함
template<typename T>
void Test_ForwardingRef(T&& param)
{
    // TODO


    // 만약 왼값 참조라면 복사
    // Test_Copy(param);
    // 오른값 참조라면 이동
    // Test_Copy(std::move(param));
    // forward를 이용
    Test_Copy(std::forward<T>(param));

    // 또한 실질적으로 param도 왼값이므로 복사생성자가 호출된다
    // move를 달아줘야함
    // Test_Copy(std::move(param));
}

int main()
{
    // 보편 참조(universal reference)
    // 전달 참조(forwarding reference) C++17부터 이렇게 바뀜

    Knight k1;
    // move는 오른값으로 바꿔준다 rvalue_cast
    Test_RValueRef(std::move(k1));

    // Test_ForwardingRef(std::move(k1));      // 오른값 참조로 들어감
    // Test_ForwardingRef(k1);         // 왼값 참조로 들어감

    // const가 붙으면 전달 참조로 작동안함
    auto&& k2 = k1;     // 왼값 참조로 바뀜
    // auto&& k2 = std::move(k1);      // Knight의 오른값 참조로 바뀜

    // template이나 auto에서만 발생하는 형상
    // 공통점 : 형식 연역 (type deduction)이 일어날 때 발생

    // 위쪽은 전달 참조를 구별하는 방법

    // --------------------------------------------

    Knight& k4 = k1;            // 왼값 참조
    Knight&& k5 = std::move(k1);    // 오른값 참조

    // 오른값 : 왼값이 아닌것 = 단일 식에서 벗어나면 사용 불가능
    // 오른값 참조 : 오른값만 참조할 수 있는 참조 타입
    // k5자체는 오른값 참조지만 오른값은 아님
    // Test_RValueRef(std::move(k5));


    Test_ForwardingRef(k1);
    Test_ForwardingRef(std::move(k1));








    return 0;
}
