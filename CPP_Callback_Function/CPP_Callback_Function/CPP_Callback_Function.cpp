#include <iostream>
using namespace std;

// 콜백 함수

class Item
{
public:

public:
    int _itemId = 0;
    int _rarity = 0;
    int _ownerId = 0;
};

class FindByOwnerId
{
public:
    bool operator()(const Item* item)
    {
        return (item->_ownerId == _ownerId);
    }
public:
    int _ownerId;
};

class FindByRarity
{
public:
    bool operator()(const Item* item)
    {
        return (item->_rarity >= _rarity);
    }
public:
    int _rarity;
};


// 다양한 조건으로 아이템을 찾을 수 있음
template<typename T>    // 어떤 함수 객체든 받을 수 있도록 한다.
Item* FindItem(Item items[], int itemCount, T selector)
{
    for (int i = 0; i < itemCount; i++)
    {
        Item* item = &items[i];
        if (selector(item))
        return item;
    }

    return nullptr;
}

int main()
{
    // 콜백(callback) : 다시 호출하다 역으로 호출하다.

    // 게임을 만들 때도 이런 콜백의 개념이 자주 등장한다. 
    // ex) MoveTask 실습 중

    // 어떤 상황이 일어나면 -> 이 기능을 호출해줘
    // ex) UI 스킬 버튼을 누르면 -> 스킬을 쓰는 함수를 호출

    Item items[10];
    items[3]._ownerId = 100;
    items[8]._rarity = 2;


    FindByOwnerId functor1;
    functor1._ownerId = 100;
    FindByRarity functor2;
    functor2._rarity = 1;

    Item* item1 = FindItem(items, 10, functor1);
    Item* item2 = FindItem(items, 10, functor2);

    return 0;
}
