#include <iostream>
#include <iomanip>
using namespace std;


const int MAX = 100;
int board[MAX][MAX] = {};
int N;

enum DIR
{
    RIGHT = 0,
    DOWN = 1,
    LEFT = 2,
    UP = 3
};

void PrintBoard()
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cout << setfill('0') << setw(2) << board[y][x] << " ";
        }
        cout << endl;
    }
}

bool CanGo(int y, int x)
{
    if (y < 0 || y >= N)
        return false;
    if (x < 0 || x >= N)
        return false;

    if (board[y][x] != 0)
        return false;
    return true;
}

void SetBoard()
{
    int dir = RIGHT;

    int num = 1;
    int y = 0;
    int x = 0;

    int dy[] = { 0, 1, 0, -1 };
    int dx[] = { 1, 0, -1, 0 };

    while (true)
    {
        board[y][x] = num;
        if (num == N * N)
            break;
        
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (CanGo(nextY, nextX))
        {
            y = nextY;
            x = nextX;
            num++;
        }
        else
        {
            dir = (dir + 1) & 4;
            /*switch (dir)
            {
            case RIGHT:
                dir = DOWN;
                break;
            case DOWN:
                dir = LEFT;
                break;
            case LEFT:
                dir = UP;
                break;
            case UP:
                dir = RIGHT;
                break;
            }*/
        }

        //switch (dir)
        //{
        //case RIGHT:
        //    nextY = y;
        //    nextX = x + 1;
        //    break;
        //case DOWN:
        //    nextY = y + 1;
        //    nextX = x;
        //    break;
        //case LEFT:
        //    nextY = y;
        //    nextX = x - 1;
        //    break;
        //case UP:
        //    nextY = y - 1;
        //    nextX = x;
        //    break;
        //}
    }
}

int main()
{
    cin >> N;

    SetBoard();

    PrintBoard();

    return 0;
}
