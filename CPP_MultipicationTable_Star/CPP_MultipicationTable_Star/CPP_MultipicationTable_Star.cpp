#include <iostream>
using namespace std;

int main()
{
    // 별 찍기
    // 유저들이 어떤 정수를 입력하면 
    // n * n개의 별을 찍었으면 좋겠어요.
    int input;
    cin >> input;

    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    // 별 찍기 (2)
    // n*n은 심심하다
    // 1개부터 시작해서 순차적으로 줄마다 증가하게 해주세요
    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    // 별 찍기 (3)
    // n개부터 시작해서 1개로 줄어들게 해주세요
    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < (input - i); j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // 구구단
    // 2단부터 9단까지 구구단을 출력
    for (int i = 2; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << i << " X " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
}
