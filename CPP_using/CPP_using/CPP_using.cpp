#include <iostream>
using namespace std;
#include <vector>
#include <list>


// using
// typedef 대신 사용할 수 있다. 

typedef vector<int>::iterator VecIt;
typedef __int64 id;     // 살짝 바꿔치기
using id2 = int;
// 1) 직관성
typedef void (*MyFunc)();
using MyFunc2 = void(*)();

// 2) 템플릿
template<typename T>
using List = std::list<T>;  // 살짝 바꿔치기
// 템플릿에선 typedef가 사용 안됨

// 없었을 때 사용 법
template<typename T>
struct List2
{
    typedef std::list<T> type;
};


int main()
{
    id playerId = 0;

    List<int> li;
    li.push_back(1);
    li.push_back(2);
    li.push_back(3);

    List2<int>::type li2;


    return 0;
}
