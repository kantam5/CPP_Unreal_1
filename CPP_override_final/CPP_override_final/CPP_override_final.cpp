#include <iostream>
using namespace std;

// override, final

class Creature
{
public:
    virtual void Attack()
    {
        cout << "Creature!" << endl;
    }
};

class Player : public Creature
{
public:
    // final은 재정의를 봉인시킨다.
    virtual void Attack() final
    {
        cout << "Player!" << endl;
    }
};

class Knight : public Player
{
public:
    // override
    // const를 붙이면 리드 온리 멤버변수 건드릴수 없음
    // const를 붙여서 새로운 문파가 만들어짐
    // 재정의 했다고 알려주는 것이 override
    // 재정의 했으면 override를 꼭 붙여주자
    virtual void Attack() override
    {
        cout << "Knight!" << endl;
    }

private:
    int _stamina = 100;
};

int main()
{
    Player* p = new Knight();

    p->Attack();




    return 0;
}
