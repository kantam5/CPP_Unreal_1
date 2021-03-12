#include <iostream>
using namespace std;

// 포인터로 넘길 떄와 구조체로 반환 받을 때의 차이

struct StatInfo
{
    int hp;         // +0
    int attack;     // +4
    int defence;    // +8
};

void EnterLoby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);
// 플레이어 승리시 true, 패배면 false
bool StartBattel(StatInfo* player, StatInfo* monster);

int main()
{
    EnterLoby();

    return 0;
}

void EnterLoby()
{
    cout << "로비에 입장했습니다.";

    StatInfo player;
    player.hp = 0xbbbbbbbb;
    player.attack = 0xbbbbbbbb;
    player.defence = 0xbbbbbbbb;
    // [매개변수][RET][지역변수 (temp(c,c,c), player(b,b,b))] [매개변수(&temp)][RET][지역변수(ret(100, 10, 2))]
    // 복사가 여러번 일어나서 낭비가 심하다.
    player = CreatePlayer();

    StatInfo monster;
    monster.hp = 0xbbbbbbbb;
    monster.attack = 0xbbbbbbbb;
    monster.defence = 0xbbbbbbbb;
    // [매개변수][RET][지역변수(monster(40,8,1))] [매개변수(&monster)][RET][지역변수()]
    CreateMonster(&monster);

    // 번외
    // 구조체끼리 복사할 때 무슨 일이 벌어질까?
    // 내부코드에서는 모든 변수에 대해서 세팅해준다. 
    // player.hp = monster.hp
    // player.attack = monster.attack
    // player.defence = monster.defence
    // 한줄 이라고 빠른게 아니다.
    //player = monster;

    bool victory = StartBattel(&player, &monster);

    if (victory)
        cout << "승리" << endl;
    else
        cout << "패배" << endl;
}

StatInfo CreatePlayer()
{
    StatInfo ret;
    
    cout << "플레이어 생성" << endl;
    ret.hp = 100;
    ret.attack = 10;
    ret.defence = 2;

    return ret;
}

void CreateMonster(StatInfo* info)
{
    cout << "몬스터 생성" << endl;

    info->hp = 40;
    info->attack = 8;
    info->defence = 1;
}

bool StartBattel(StatInfo* player, StatInfo* monster)
{
    while (true)
    {
        int damage = player->attack - monster->defence;
        if (damage < 0)
            damage = 0;

        monster->hp -= damage;
        if (monster->hp < 0)
            monster->hp = 0;

        cout << "몬스터의 HP : " << monster->hp << endl;

        if (monster->hp == 0)
            return true;

        damage = monster->attack - player->defence;
        if (damage < 0)
            damage = 0;

        player->hp -= damage;
        if (player->hp < 0)
            player->hp = 0;

        cout << "플레이어의 HP : " << player->hp << endl;

        if (player->hp == 0)
            return false;
    }
}