#include <iostream>
using namespace std;

// 함수 포인터

int Add(int a, int b)
{
    return a + b;
}

int Sub(int a, int b)
{
    return a - b;
}

class Item
{
public:
    Item() : _itemId(0), _rarity(0), _ownerId(0)
    {

    }

public:
    int _itemId;
    int _rarity;
    int _ownerId;
};

typedef bool(ITEM_SELECTOR)(Item*, int);


// 동작 자체를 넘겨준다.
// 공동적인 코드가 엄청 불어난다. 동작을 인자로 넘길 수 있으면 편해질 것이다.
Item* FindItem(Item items[], int itemCount, ITEM_SELECTOR* selector, int value)
{
    for (int i = 0; i < itemCount; i++)
    {
        Item* item = &items[i];
        if (selector(item, value))
            return item;
    }

    return nullptr;
}

bool IsRareItem(Item* item, int value)
{
    return item->_rarity >= value;
}

bool IsOwnerItem(Item* item, int ownerId)
{
    return item->_ownerId == ownerId;
}



int main()
{
    int a = 10;
    // 1) 포인터 *
    // 2) 변수 이름 pointer
    // 3) 데이터 타입 int
    int* pointer = &a;

    typedef int DATA;

    DATA* pointer2 = &a;

    // 함수의 이름은 함수의 시작 주소(배열과 유사) Add(0001adcdd) 어셈
    int result = Add(1, 2);
    cout << result << endl;

    // 함수
    typedef int(FNC_TYPE)(int, int);    // int 2개를 받고 int 1개를 뱉는 함수를 FNC_TYPE이라 명명
    // using FNC_TYPE = int(int a, int b); // modern c++에서

    // 1) 포인터 *
    // 2) 변수 이름 fn
    // 3) 데이터 타입 FNC_TYPE
    FNC_TYPE* fn;
    // 함수 포인터
    fn = Sub;   // 여기 하나만 고치면 함수를 쉽게 바꿀 수 있다.

    result = fn(1, 2);  // 기본 뭄법
    cout << result << endl;

    result = (*fn)(1, 2);   // *접근 연산자를 붙여도 함수 주소! 똑같음
    cout << result << endl;

    Item items[10] = {};
    items[3]._rarity = 2;

    Item* rareItem = FindItem(items, 10, IsOwnerItem, 100);

    return 0;
}