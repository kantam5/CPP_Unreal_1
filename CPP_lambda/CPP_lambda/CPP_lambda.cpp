#include <iostream>
using namespace std;
#include <vector>


// 람다(lambda)

// 함수 객체를 빠르게 만드는 문법

enum class ItemType
{
    None,
    Armor,
    Weapon,
    Jewelry,
    Consumable
};

enum class Rarity
{
    Common,
    Rare,
    Unique
};


class Item
{
public:
    Item() {}
    Item(int itemId, Rarity rarity, ItemType itemType)
        : _itemId(itemId), _rarity(rarity), _type(itemType)
    {

    }
public:
    int _itemId = 0;
    Rarity _rarity = Rarity::Common;
    ItemType _type = ItemType::None;
};

int main()
{
    vector<Item> v;
    v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
    v.push_back(Item(2, Rarity::Common, ItemType::Armor));
    v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
    v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

    // 람다 = 함수 객체를 손쉽게 만드는 문법
    // 람다 자체로 C++11에 새로운 기능이 들어간 것은 아니다.
    {
        struct IsUniuqeItem
        {
            bool operator()(Item& item)
            {
                return item._rarity == Rarity::Unique;
            }
        };

        // 람다 표현
        auto isUniqueLambda = [](Item& item) 
        {
            return item._rarity == Rarity::Unique; 
        };
        // 이름이 지어지지 않은 함수

        auto findIt = std::find_if(v.begin(), v.end(),
            [](Item& item){return item._rarity == Rarity::Unique;});

        if (findIt != v.end())
            cout << "아이템 ID: " << findIt->_itemId << endl;
    }

    {
        struct FindItem
        {
            FindItem(int itemId, Rarity rarity, ItemType type)
                : _itemId(itemId), _rarity(rarity), _type(type)
            {

            }
            bool operator()(Item& item)
            {
                return item._itemId == _itemId && item._rarity == _rarity && item._type == _type;
            }
            int _itemId;
            Rarity _rarity;
            ItemType _type;
        };

        // 람다 표현
        // 클로저 (closure) = 람다에 의해 만들어진 실행시점 객체
        auto isUniqueLambda = [](Item& item)
        {
            return item._rarity == Rarity::Unique;
        };
        // 이름이 지어지지 않은 함수

        int itemId = 4;
        Rarity rarity = Rarity::Unique;
        ItemType type = ItemType::Weapon;
        // [ ] 캡쳐(capture) : 함수 객체 내부에 변수를 저장하는 개념과 유사
        // 사진을 찍듯 일조으이 스냅샷을 찍는다고 이해
        // 기본 캡쳐 모드 : 값(복사) 방식(=) 참조 방식(&)
        // 값 방식은 itemId의 4라는 값을 복사해서 가져오고
        // 참조 방식은 itemId의 주소를 가져와서 사용
        // 변수마다 캡쳐모드를 달리해서 사용 가능 되도록 이렇게 하자
        // 외부에 있는 itemId를 가져와서 사용 : 값 방식(name), 참조 방식(&name)
        // [=, &name]도 사용 가능
        auto findByItemIdByLambda = [=, &type](Item& item) 
        {
            return item._itemId == itemId && item._rarity == rarity && item._type == type;
        };
        itemId = 10;

        auto findIt = std::find_if(v.begin(), v.end(), FindItem(4, Rarity::Unique, ItemType::Weapon));


        if (findIt != v.end())
            cout << "아이템 ID: " << findIt->_itemId << endl;
    }

    {
        class Knight
        {
        public:
            auto ResetHpJob()
            {
                // 무작정 =로 넘기는건 위험하다 
                // this로 넘겨주면 경각심을 가지게 된다
                auto f = [this]() 
                {
                    this->_hp = 200;
                };

                return f;
            }
        public:
            int _hp = 100;
        };

        class Functor
        {
        public:
            Functor(Knight* k) : _knight(k)
            {

            }
            void operator()()
            {
                _knight->_hp = 200;
            }
        public:
            Knight* _knight;
        };

        Knight* knight = new Knight();
        auto job = knight->ResetHpJob();
        delete knight;
        job();      // 미리 delete를 시켰다면 메모리를 오염시킨다.
    }


    return 0;
}
