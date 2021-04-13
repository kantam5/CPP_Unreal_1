#include <iostream>
using namespace std;
#include <vector>
#include <list>

// List
// 면접 단골 Vector vs List

// vector : 동적 배열
// [                 ]
// [                                      ] 증설
// 복붙으로 이전

// list : 연결 리스트
// [1] -> [2] -> [3] -> [4] -> [5]      일단 이건 단일 연결 리스트
// 메모리상에 연속적으로 존재하지 않고 다음 데이터가 어디있는지만 알고있다.
// 데이터를 저장하는 칸 단위를 node라 한다.
// [1] <-> [2] <-> [3] <-> [4] <-> [5]  이중 연결 리스트
// [1] -> [2] -> [3] -> [4] -> [5] -> [1] -> [2] ... 원형 연결 리스트


class Node
{
public:
    Node* _next;    // 다음 노드를 가리키는 포인터
    // 포인터는 주소를 가리키므로 크기가 일정하다
    // -> 클래스안에서 포인터로 자기자신을 가리킬 수 있다. 
    Node* _prev;    // 이중 연결 리스트
    int _data;
};

int main()
{
    // list(연결 리스트)
    // - list의 동작 원리
    // - 중간 삽입/삭제
    // - 처음/끝 삽입/삭제
    // - 임의 접근

    list<int> li;
    
    for (int i = 0; i < 100; i ++ )
    {
        li.push_back(i);
    }

    // li.push_front(10);  // vector는 처음 삽입이 없다. 왜냐 비효율적임
    int size = li.size();
    // 리스트는 동적인 데이터가 아니기 때문에 capacity의 개념이 없다.

    int first = li.front();
    int last = li.back();

    // li[2] = 4;  // [ ] 임의 접근 허용 안함

    list<int>::iterator itBegin = li.begin();
    list<int>::iterator itEnd = li.end();
    
    for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
    {
        cout << *it << endl;
    }

    li.insert(itBegin, 100);

    li.erase(li.begin());   
    li.pop_front();     // 맨처음 값 삭제
    li.pop_back();

    li.remove(10);      // 10이라는 데이터를 삭제

    return 0;
}
