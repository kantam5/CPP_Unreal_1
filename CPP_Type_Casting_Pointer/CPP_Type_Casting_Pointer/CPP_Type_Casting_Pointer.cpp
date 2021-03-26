#include <iostream>
using namespace std;

enum ItemType
{
    IT_WEAPON = 1,
    IT_ARMOR = 2
};

// 타입 변환 (포인터)
class Knight
{
public:
    int _hp = 0;
};

// 최상위 부모의 소멸자에 virtual을 붙이는 것을 잊지 말자
// 그러면 상속받은 클래스의 소멸자에도 virtual이 붙여지게 된다.
// 가상함수 테이블이 객체마다 생성되어 부모 자식간의 관계에서도 본래의 소멸자를 호출하게 된다.
class Item
{
public:
    Item()
    {
        cout << "Item()" << endl;
    }
    Item(int itemType) : _itemType(itemType)
    {
        cout << "Item(int itemType)" << endl;
    }
    Item(const Item& item)
    {
        cout << "Item(const Item&)" << endl;
    }
    virtual ~Item()
    {
        cout << "~Item()" << endl;
    }

    virtual void Test()
    {
        cout << "Test Item" << endl;
    }

public:
    int _itemType = 0;
    int _itemDbId = 0;

    char _dummy[4096] = { };    // 이런 정보들로 인해 비대해진 것을 묘사
};

class Weapon : public Item
{
public:
    Weapon() : Item(IT_WEAPON)
    {
        cout << "Wapon()" << endl;
        _damage = rand() % 100;
    }
    virtual ~Weapon()
    {
        cout << "~Wapon()" << endl;
    }

    virtual void Test()
    {
        cout << "Test Weapon" << endl;
    }

public:
    int _damage = 0;
};

class Armor : public Item
{
public:
    Armor() : Item(IT_ARMOR)
    {
        cout << "Armor()" << endl;
        _defence = rand() % 100;
    }
    virtual ~Armor()
    {
        cout << "~Armor()" << endl;
    }

public:
    int _defence = 0;
};

// 복사로 넘겨줘도 객체를 생성, 소멸 (복사 생성자 사용)
void TestItem(Item item)
{

}

void TestItemPtr(Item* item)
{
    item->Test();
}

int main()
{
    //{
    //    // Stack [type(4) dbid(4) dummy(4096)]
    //    Item item;

    //    // Stack [주소[4~8]] -> Heap[type(4) dbid(4) dummy(4096)]
    //    Item* item2 = new Item();
    //    // 소멸자를 호출 안함 스택에 있는 item2만 소멸
    //    // memory leak -> 점점 가용 메모리가 줄어들어 crash발생
    //    // delete를 호출해야 된다. 

    //    // 복사 비용
    //    TestItem(item);
    //    TestItem(*item2);

    //    // 아무런 부하 없음
    //    TestItemPtr(&item);
    //    TestItemPtr(item2);

    //    delete item2;
    //}

    //// 배열
    //{
    //    cout << "-----------------------------------" << endl;
    //    // 진짜 아이템이 100개 있는 것 [스택 메모리에 올라와 있는]
    //    Item item3[100] = {};

    //    cout << "-----------------------------------" << endl;
    //    // 아이템이 100개 있을까? -> NO
    //    // 아이템을 가리키는 바구니가 100개 있다는 것일뿐 실제 아이템은 1개도 없을 수도 있음
    //    Item* item4[100] = {};

    //    for (int i = 0; i < 100; i++)
    //    {
    //        item4[i] = new Item();
    //    }
    //    cout << "-----------------------------------" << endl;
    //    for (int i = 0; i < 100; i++)
    //    {
    //        delete item4[i];
    //    }
    //    cout << "-----------------------------------" << endl;

    //}

    // 연관성이 없는 클래스 사이의 포인터 변환 테스트
    {
        // Stack[주소] -> Heap[_hp(4)]
        Knight* knight = new Knight();

        // Stack[주소(위의 나이트의 주소]
        //Item* item = (Item*)knight; // 암시적으론 안되는데 명시적으론 가능
        //item->_itemType = 2;
        //item->_itemDbId = 1;    // fdfdfdfd로 된 부분을 건드리면 이런! 엉뚱한 곳을 침범

        delete knight;
    }

    // 연관성이 있는
    // 자식 -> 부모 변환 테스트
    {
        Item* item = new Item();

        // [ [ item ] ]
        // [ [ item ] _damage  ]
        //Weapon* weapon = (Weapon*)item;      // 위험 명시적으로 가능
        //weapon->_damage = 10;                // 메모리 초과

        delete item;
    }
    // 부모 -> 자식 변환 테스트
    {
        // [ [ item ] ]
        // [ [ item ] _damage  ]
        Weapon* weapon = new Weapon();

        Item* item = weapon;        // 가능 암시적 명시적으로도 가능

        TestItemPtr(item);
        delete weapon;
    }

    // 명시적으로 타입 변환할 때는 항상 항상 조심해야 한다
    // 암시적으로 될 때는 안전한가?
    // -> 평생 명시적으로 타입 변환(캐스팅)은 안하면 되는거 아닌가?

    Item* inventory[20] = {};

    srand((unsigned int)time(nullptr));
    for (int i = 0; i < 20; i++)
    {
        int randValue = rand() % 2;
        switch (randValue)
        {
        case 0:
            inventory[i] = new Weapon();
            break;
        case 1:
            inventory[i] = new Armor();
            break;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        Item* item = inventory[i];
        if (item == nullptr)
            continue;
        
        if (item->_itemType == IT_WEAPON)
        {
            // 현재 item이 Weapon을 가리키고 있어서 안전하지만 혹시 원본이 Weapon이 아니라면 잘못된 타입 변환
            Weapon* weapon = (Weapon*)item; 
            cout << "Weapon Damage : " << weapon->_damage << endl;
        }
        else
        {
            Armor* armor = (Armor*)item;
            cout << "Armor Defence : " << armor->_defence << endl;
        }
    }

    // ------------------------- 매우 매우 매우 중오 -----------------------
    for (int i = 0; i < 20; i++)
    {
        Item* item = inventory[i];
        if (item == nullptr)
            continue;

        delete item;

        // 소멸자에 virtual을 붙여주면 밑의 과정이 필요없다.
        /*if (item->_itemType == IT_WEAPON)
        {
            Weapon* weapon = (Weapon*)item;
            delete weapon;
        }
        else
        {
            Armor* armor = (Armor*)item;
            delete armor;
        }*/

        // item의 소멸자만 호출되는게 아니라 웨펀이나 아머의 소멸자가 먼저 호출되고 아이템 소멸자가 호출되야함
        // delete item;    
    }

    // [결론]
    // - 포인터 vs 일반 타입 : 차이를 이해하자
    // - 포인터 사이의 타입 변환 (캐스팅) 매우 매우 매우 조심해야 한다.
    // - 부모-자식 관계에서 부모 클래스의 소멸자에는 까먹지 말고 virtual을 붙이자!!! 면접 쌉단골

    return 0;
}
