#include <iostream>
#include <vector>
using namespace std;

// vector
// 면접


int main()
{
    // STL (Standard Template Library)
    // 프로그래밍을 할 때 필요한 자료구조/ 알고리즘들을
    // 템플릿으로 제공하는 라이브러리

    // 컨테이너(Container) : 데이터를 저장하는 객체(자료구조 Data Structure)

    // vector (동적 배열)
    // - vector의 동작 원리 (size / capacity)
    // - 중간 삽입 / 삭제
    // - 처음 / 끝 삽입/삭제
    // - 임의 접근

    // 배열의 단점 (vector의 필요성)
    const int MAX_SIZE = 10;
    int arr[MAX_SIZE] = {};
    for (int i = 0; i < MAX_SIZE; i++)
        arr[i] = i;
    for (int i = 0; i < MAX_SIZE; i++)
        cout << arr[i] << endl;
    // 배열에 좀 더 추가를 해주고 싶다면 어떻게 해야하나
    // 배열의 크기를 어떻게 늘리는가
    // -> 엄청나게 크게 만든다면 메모리를 낭비
    // -> 배열로는 불가. 결정이 되면 딱 만들어짐

    // 동적 배열
    // 매우 매우 중요한 개념 -> 어떤 마법으로 배열을 유동적으로 사용한 것인가
    // 1) 여유분을 두고 메모리를 할당한다.
    // - [  ] 필요한 크기  -> [          ] 여유
    // 2) 여유분까지 꽉 찾으면, 메모리를 증설한다.
    // - [---------] -> [---------          ]
    
    // Q1) 여유분을 얼만큼이 적당한가
    // Q2) 증설은 얼만큼이 적당한가
    // Q3) 기존의 데이터는 어떻게 처리되는가
    // [1 2 3 4 5]
    // [1 2 3 4 5         ]
    // -> 새로운 지역의 메모리에서 보다 큰 용량을 확보해서 복붙한다.
    // -> size가 1늘어날 때마다 capacity를 1늘리면 복붙 비용이 엄청나다
    // -> 여유롭게 증설 1.5배 씩

    vector<int> v(1000, 0);     // 1000 size에 초기화는 0
    vector<int> v2 = v;         //  복사
    //v.push_back(1);   
    //v.push_back(2);   
    //v.push_back(3);   
    //v.push_back(4);  
    //v.push_back(5); 

    // v.resize(1000);     // 처음부터 1000의 사이즈 사용 물론 자동으로 capacity도 늘어남
    cout << v.size() << " " << v.capacity() << endl;

    // size : 실제 사용 데이터 개수
    // 1 2 3 4 5 6 ... 1씩 증가하는게 당연
    // capacity : 여유분을 포함한 총 용량 개수
    // 1 2 3 4 5 6 7 8 9 13 19 28 42 63 ... 대략 이전 capacity의 1.5배
    // 용량 증가는 컴파일러마다 다름
    // 그냥 1개넣을 때마다 용량을 1증가시키면 안되나 -> 위의 Q3

    // v.reserve(1000);    // 처음부터 1000의 capacity를 확보
    // capacity가 늘어날 때마다 복사 비용이 드므로
    // 원하는 크기만큼 처음에 확보한다.

    for (int i = 0; i < 1000; i++)
    {
        // v.[i] = 100;
        v.push_back(100);
        cout << v.size() << " " << v.capacity() << endl;
    }

    v.pop_back();       // 넣은걸 끄집어냄
    v.back();           // 맨 마지막에 넣은걸 보고싶음
    v.front();          // 맨 처음에 넣은걸 보고싶음


    v.clear();      // clear을 시켜도 capacity는 줄어들지 않음
    vector<int>().swap(v); // 임시로 만든 vector와 기존의 vector을 바꿔서 capacity를 줄임
    // 위쪽 줄 다음이 실행되면 바로 임시 벡터는 소멸됨
    cout << v.size() << " " << v.capacity() << endl;

    //const int size = v.size();
    //for (int i = 0; i < size; i++)
    //{
    //    cout << v[i] << endl;
    //}

    return 0;
}
