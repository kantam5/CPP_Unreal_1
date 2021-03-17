﻿#include <iostream>
using namespace std;

// main
// - EnterLoby
// -- CreatPlayer
// -- EnterGame
// --- CreatMonsters
// --- EnterBattle

enum PlayerType
{
    PT_Knight = 1,
    PT_Archer = 2,
    PT_Mage = 3,
};
enum MonsterType
{
    MT_Slime = 1,
    MT_Orc = 2,
    MT_Skeleton = 3,
};
struct StatInfo
{
    int hp = 0;
    int attack = 0;
    int defence = 0;
};

void EnterLoby();
void PrintMessage(const char* msg);
void CreatPlayer(StatInfo* playerInfo);
void PrintStatInfo(const char* name, const StatInfo& info);
void EnterGame(StatInfo* playerInfo);
void CreatMonsters(StatInfo monsterInfo[], int count);
bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo);

int main()
{
    srand((unsigned)time(nullptr));
    EnterLoby();


    return 0;
}

void EnterLoby() 
{
    while (true)
    {
        PrintMessage("로비에 입장하였습니다.");

        // Player
        StatInfo playerInfo;
        CreatPlayer(&playerInfo);       // 포인터
        PrintStatInfo("Player", playerInfo);    // 참조

        EnterGame(&playerInfo);
    }
}

void PrintMessage(const char* msg)
{
    cout << "----------------------------------" << endl;
    cout << msg << endl;
    cout << "----------------------------------" << endl;
}

void CreatPlayer(StatInfo* playerInfo)
{
    bool ready = false;
    while (ready == false)
    {
        PrintMessage("캐릭터 생성");
        PrintMessage("(1) 기사  (2) 궁수  (3) 법사");
        cout << " > ";

        int input;
        cin >> input;

        switch (input)
        {
        case PT_Knight:
            playerInfo->hp = 100;
            playerInfo->attack = 10;
            playerInfo->defence = 5;
            ready = true;
            break;
        case PT_Archer:
            playerInfo->hp = 80;
            playerInfo->attack = 15;
            playerInfo->defence = 3;
            ready = true;
            break;
        case PT_Mage:
            playerInfo->hp = 50;
            playerInfo->attack = 25;
            playerInfo->defence = 1;
            ready = true;
            break;
        }
    }
}

void PrintStatInfo(const char* name, const StatInfo& info)
{
    cout << "-------------------------------" << endl;
    cout << name << " : HP=" << info.hp << " : ATK=" << info.attack << " : DEF=" << info.defence << endl;

}

void EnterGame(StatInfo* playerInfo)
{
    const int MONSTER_COUNT = 2;
    PrintMessage("게임에 입장했습니다.");
    
    while (true)
    {
        StatInfo monsterInfo[MONSTER_COUNT];
        CreatMonsters(monsterInfo, MONSTER_COUNT);

        for (int i = 0; i < MONSTER_COUNT; i++)
        {
            PrintStatInfo("Monster", monsterInfo[i]);
        }

        PrintStatInfo("Player", *playerInfo);

        PrintMessage("[1] 전투  [2] 전투  [3] 도망");

        int input;
        cin >> input;

        if (input == 1 || input == 2)
        {
            int index = input - 1;
            bool victory = EnterBattle(playerInfo, &monsterInfo[index]);
            if (victory == false)
                break;
        }
    }
}

void CreatMonsters(StatInfo monsterInfo[], int count)
{
    for (int i = 0; i < count; i++)
    {
        int randValue = 1 + rand() % 3;
        switch (randValue)
        {
        case MT_Slime:
            monsterInfo[i].hp = 30;
            monsterInfo[i].attack = 5;
            monsterInfo[i].defence = 1;
            break;
        case MT_Orc:
            monsterInfo[i].hp = 40;
            monsterInfo[i].attack = 8;
            monsterInfo[i].defence = 3;
            break;
        case MT_Skeleton:
            monsterInfo[i].hp = 50;
            monsterInfo[i].attack = 10;
            monsterInfo[i].defence = 5;
            break;
        }
    }
}

bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo)
{
    while (true)
    {
        int damage = playerInfo->attack - monsterInfo->defence;
        if (damage < 0)
            damage = 0;

        monsterInfo->hp -= damage;
        if (monsterInfo->hp < 0)
            monsterInfo->hp = 0;

        PrintStatInfo("Monster", *monsterInfo);

        if (monsterInfo->hp == 0)
        {
            PrintMessage("몬스터를 처치했습니다.");
            return true;
        }

        damage = monsterInfo->attack - playerInfo->defence;
        if (damage < 0)
            damage = 0;

        playerInfo->hp -= damage;
        if (playerInfo->hp < 0)
            playerInfo->hp = 0;

        PrintStatInfo("Player", *playerInfo);

        if (playerInfo->hp == 0) {
            PrintMessage("Game Over");
            return false;
        }
    }
}

// 포인터는 주소 참조는 실체