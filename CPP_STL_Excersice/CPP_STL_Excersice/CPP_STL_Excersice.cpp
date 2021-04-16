#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

// STL 연습문제
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<int> v;

    for (int i = 0; i < 100; i++)
    {
        int num = rand() % 100;
        v.push_back(num);
    }

    // Q1) number라는 숫자가 벡터에 체크하는 기능 (bool, 첫 등장 iterator)
    {
        int number = 50;

        bool found = false;
        vector<int>::iterator itFound;
        for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        {
            if (*it == number) {
                itFound = it;
                found = true;
                break;
            }
        }
        cout << *itFound << " " << found << endl;
    }

    // Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능
    {
        bool found = false;
        vector<int>::iterator itFound;
        for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        {
            if (*it % 11 == 0)
            {
                itFound = it;
                found = true;
                break;
            }
        }
        cout << *itFound << " " << found << endl;
    }

    // Q3) 홀수인 숫자인 개수
    {
        int count = 0;
        for (unsigned int i = 0; i < v.size(); i++)
        {
            if (v[i] % 2 == 1)
                count++;
        }
        cout << count << endl;
    }

    // Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주셈
    {
        for (unsigned int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
            v[i] = v[i] * 3;
            cout << v[i] << endl;
        }
    }




    return 0;
}
