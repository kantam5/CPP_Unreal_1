#include <iostream>
#include"Game.h"
using namespace std;

// TextRPG OOP



int main()
{
    srand((unsigned int)time(nullptr));
    Game game;
    game.Init();    // 초기화

    while (true)
    {
        game.Update();
    }


    return 0;
}
