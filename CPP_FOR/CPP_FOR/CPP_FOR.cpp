#include <iostream>
using namespace std;


int main()
{
    int count = 0;

    // while - 동안에
    // ex) 유저가 게임을 종료할때 까지 계속 게임을 실해해라
    // 목적지에 도달할 때 까지 계속 이동하라
    while (count < 5)
    {
        cout << "Hello World" << endl;
        count++;
    }

    do // 무조건 한번은 실행, 잘 안쓰임
    {
        cout << "Hello World" << endl;
    } while (false);

    for (int count = 0; count < 5; count++)
    {
        cout << "Hello World" << endl;
    }

    // 루프문의 흐름 제어
    // break, continue
    // break는 반복문에서 무조건 빠져나가라. break가 있는 {}의 반복을 빠져나감
    // continue는 지금 실행중인 반복을 넘기고 다음 반복을 실행
    int round = 1;
    int hp = 100;
    int damage = 30;
    
    // 무한 루프 : 전투 시작
    while (true)
    {
        hp -= damage;
        if (hp < 0)
            hp = 0; // 음수 체력을 0으로 보정

        // 시스템 메시지
        cout << "ROUND " << round << "  몬스터 체력 " << hp << endl;

        if (hp == 0)
        {
            cout << "몬스터 처치" << endl;
            break;
        }

        if (round == 5)
        {
            cout << "제한 라운드 종료" << endl;
            break;
        }

        round++;
    }

    // 1에서 10 사이의 홀수만 출력
    for (int count = 1; count <= 10; count++) {
        bool isEven = (count % 2 == 0);
        if (isEven)
            continue;   // 바로 count++로 
        cout << count << endl;
    }


    // 정해진 횟수 만큼 실행한다 혹은 정해진 범위가 있다면 for문을 쓰는게 좋다
    // 기능적으로는 while, for 똑같다.
}
