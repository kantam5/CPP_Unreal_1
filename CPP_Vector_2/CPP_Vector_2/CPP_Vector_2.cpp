#include <iostream>
#include <vector>
using namespace std;

// vector 2
// 면접


int main()
{
    // 반복자(iterator) : 포인터와 유사한 개념, 컨테이너의 원소(데이터)를 가리키고
    // 다음 / 이전 원소로 이동 가능
    // 각각의 컨테이너 들은 자신만의 반복자를 가지고 있음

    vector<int> v(10);
    v.reserve(1000);

    for (vector<int>::size_type i = 0; i < v.size(); i++)
        v[i] = i;

    //vector<int>::iterator it;
    //it = v.begin();     // begin은 v의 iterator을 반환한다.
    //int* ptr;
    //ptr = &v[0];
    //
    //cout << *it << endl;
    //cout << *ptr << endl;

    //it++;
    //++it;
    //ptr++;
    //++ptr;      // ++ 지원

    //it += 2;
    //it = it - 2;    // 포인터처럼 데이터를 가리키는게 포인터처럼 가능


    // 다른 컨테이너는 v[i]와 같은 인덱스 접근이 안될 수도 있음
    // iterator은 vector뿐 아니라 다른 컨테이너에도 공통적으로 있는 개념이라 사용한다.
    vector<int>::iterator itBegin = v.begin();
    vector<int>::iterator itEnd = v.end();    // 끝나는 iterator반환, 쓰레기값이 들어있음

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << (*it) << endl;
    }

    int* ptrBegin = &v[0]; // v.begin()._Ptr;
    int* ptrEnd = ptrBegin + 10; // v.end()._Ptr;
    for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr)
    {
        cout << *ptr << endl;
    }

    // const int*   
    // read only
    vector<int>::const_iterator cit1 = v.cbegin();
    
    // 역방향
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
    {
        cout << (*it) << endl;
    }

    // - 중간 삽입/삭제  (비효율적/비효율적)
    // - 처음/끝 삽입/삭제  (비효율적/효율적)
    // - 임의 접근 (Random Access)

    // vector = 동적 배열 = 동적으로 사이즈가 커지는 배열 = 일단 배열
    // 원소가 하나의 메모리 블록에 연속하게 저장된다!!
    
    // 중간 삽입
    // [                        ]
    // [0] [1] [2] [3] [4] [] []
    // 중간에 [5]를 넣으려면 뒤로 데이터를 옮겨야 한다.
    // 비효울적이다.
    // 중간 삭제
    // [                        ]
    // [0] [1] [] [3] [4] [] []
    // 나머지 데이터들을 한 칸씩 끌어와야 한다.
    // 비효율적이다.

    // 처음 삽입/삭제
    // [                        ]
    // [] [1] [2] [3] [4] [] []
    // 나머지를 땡기고 밀어야됨
    // 비효율적이다
    // 끝 삽입/삭제
    // [                        ]
    // [0] [1] [2] [3] [4] [] []
    // 끝은 땡기거나 미는게 없다.
    // 효율적이다.

    // 임의 접근 (Random Access)
    // i번째 데이터는 어디 있습니까?
    // 사용하는 메모리가 뭉쳐있기에 가능하다.
    // v[2] = 3;

    // vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5); // v.begin()으로 처음위치와의 기준을 잡는다.
    // vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);
    // vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4); // 범위 삭제 v.begin() + 2 <= 삭제 < v.begin() + 4
    // 위 모두 동작한 위치를 반환한다.


    // 쭉 스캔을 하면서, 3이라는 데이터가 있으면 일괄 삭제하고 싶다.
    for (vector<int>::iterator it = v.begin(); it != v.end();)
    {
        int data = *it;
        if (data == 3)
        {
            it = v.erase(it);
            // v.erase(it);        // erase하는 순간 it는 사라진다.
            // break;              // 하나만 없앤다면
        }
        else
            ++it;   // 삭제한다면 밀려온 데이터를 가리키게 되므로 아니면 다음 데이터로 넘어가는게 맞다.
    }




    return 0;
}