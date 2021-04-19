#include <iostream>
using namespace std;
#include <vector>
#include <map>
// auto

class Knight
{
public:
    int _hp;
};

template<typename T>
void Print(T t)
{
    cout << t << endl;
}

int main()
{
    // Modern C++ (C++11 부터)
    /*int a = 3;
    float b = 0.4f;
    double c = 1.22;
    Knight d = Knight();
    const char* e = "ddd";*/

    // 오른쪽을 보고 알아서 타입을 골라준다.
    auto a = 3;
    auto b = 0.4f;
    auto c = 1.22;
    auto d = Knight();
    auto e = "ddd";

    // auto는 일종의 조커 카드
    // template 느낌
    // 형식 연역 (type deduction)
    // -> 말이 되게 알아서 잘 맞춰줘 (추론)
    // 추론 규칙은 생각보다 복잡해질 수 있다.

    auto f = &d;
    const auto test1 = b;
    auto* test2 = e;

    // 주의!
    // 기본 auto는 const, & 무시!!!!!!!
    int& reference = a;
    const int cst = a;
    // &, const 빼서 int
    auto test3 = reference;
    auto test4 = cst;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (vector<int>::size_type i = 0; i < v.size(); i++)
    {
        auto& data = v[i];   // int&

        data = 100;
    }

    // 모든 타입을 auto로 바꾼다면?
    // NO(주관적인 생각)
    // -> 타이핑이 짧아 지는건 인정
    // -> 하지만 가독성이 떨어진다.
    // -> 일반적으론 그냥 놔둬
    
    map<int, int>m;
    m.insert(make_pair(1, 100));
    
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }


    return 0;
}
