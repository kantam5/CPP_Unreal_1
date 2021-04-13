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

// 중간 삽입 삭제시 next와 prev를 잘 조작하면 벡터와 달리 간단하다.

// stl에서 구현을 할때 가상의 노드를 하나 만든다.
// [1] <-> [2] <-> [3] <-> [4] <-> [5] <-> [ _Myhead = end()] <-> [1]


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
    // - 중간 삽입/삭제 (good/good)
    // - 처음/끝 삽입/삭제 (good/good)
    // - 임의 접근 (i번때 데이터는 어디 있는지 알수 있나? 직접 포인터를 타고 가봐야 한다.)
    // 비효율적이라 기능적으로 제공하지 않음

    list<int> li;
    list<int>::iterator itRemember;
    
    for (int i = 0; i < 100; i ++ )
    {
        if (i == 50)
        {
            itRemember = li.insert(li.end(), i);
        }
        else
        {
            li.push_back(i);
        }
    }

    // li.push_front(10);  // vector는 처음 삽입이 없다. 왜냐 비효율적임
    int size = li.size();
    // 리스트는 동적인 데이터가 아니기 때문에 capacity의 개념이 없다.

    int first = li.front();
    int last = li.back();

    // li[2] = 4;  // [ ] 임의 접근 허용 안함

    list<int>::iterator itBegin = li.begin();
    list<int>::iterator itEnd = li.end();
    
    int* ptrBegin = &(li.front());
    int* ptrEnd = &(li.back());

    // list<int>::iterator it2 = itBegin + 10; // 포탈을 타고 10번을 가야된다. 존나 멀다
    // 지원안함 1칸은 지원

    // list<int>::iterator itTest1 = --itBegin; 맨처음에서 뒤로가면 error
    // list<int>::iterator itTest2 = --itEnd;
    // list<int>::iterator itTest3 = ++itEnd;

    for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
    {
        cout << *it << endl;
    }

    li.insert(itBegin, 100);

    li.erase(li.begin());   
    li.pop_front();     // 맨처음 값 삭제
    li.pop_back();

    li.remove(10);      // 10이라는 데이터를 삭제
    // 중간 삽입이 간단하여 remove를 지원한다.
    

    // * 임의 접근이 느리다고 했는데 중간 삽입/삭제는 빠르다 그이유는?
    // 50번 인덱스에 있는 데이터를 삭제한다면
    list<int>::iterator it = li.begin();
    for (int i = 0; i < 50; i++)
        it++;
    li.erase(it);
    // 이렇게 50번째 인덱슬를 찾아서 삭제한다면 느리겠지만
    // 우리가 삭제해야할 인덱스를 이미 찾아놨다면 삭제는 빠르다.
    // 이를 분간하도록 하자. 위아래 차이
    li.erase(itRemember);

    return 0;
}
