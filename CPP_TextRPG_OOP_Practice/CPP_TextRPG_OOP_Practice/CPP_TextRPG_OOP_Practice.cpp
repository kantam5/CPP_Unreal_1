#include <iostream>
using namespace std;
#include "Player.h"

// 전방선언


int main()
{
    // Player는 몇 바이트?
    // int 2개니까 8바이트

    // sizeof(Monster*) = 4 or 8
    Player p1;

    Player* p2 = new Player();

    return 0;
}
