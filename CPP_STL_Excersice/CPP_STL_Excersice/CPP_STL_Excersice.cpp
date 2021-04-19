#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
// STL 연습문제
// 알고리즘

// 자료구조 [데이터를 저장하는 구조]
// 알고리즘 [데이터를 어떻게 사용할 것인가]
// 현업에서 가장 많이 사용되던거
// find
// find_if
// count
// count_if
// all_if
// any_of
// none_of
// for_each
// remove
// remove_if


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

        // 위와 완전히 똑같음
        itFound = find(v.begin(), v.end(), number);
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

        // 위와 완전히 똑같음
        struct CanDivideby11    // 함수 객체
        {
            bool operator()(int a)
            {
                return (a % 11 == 0);
            }
        };
        // itFound = find_if(v.begin(), v.end(), CanDivideby11());
        itFound = find_if(v.begin(), v.end(), [](int n) {return n % 11 == 0; });
        // 람다식 표현
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

        struct IsOdd
        {
            bool operator()(int n)
            {
                return (n % 2 != 0);
            }
        };

        // count = count_if(v.begin(), v.end(), IsOdd());
        count = count_if(v.begin(), v.end(), [](int n) {return n % 2 != 0; });
        

        // 모든 데이터가 조건을 만족하느냐
        bool b1 = all_of(v.begin(), v.end(), IsOdd());
        bool b2 = any_of(v.begin(), v.end(), IsOdd());
        bool b3 = none_of(v.begin(), v.end(), IsOdd());

        int breakPoint = 2;
    }

    // Q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱해주셈
    {
        for (unsigned int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
            v[i] = v[i] * 3;
            cout << v[i] << endl;
        }
        struct MultiplyBy3
        {
            void operator()(int &n)
            {
                n = n * 3;
            }
        };
        // 간단하게 데이터를 하나씩 스캔할 때
        for_each(v.begin(), v.end(), MultiplyBy3());
    }

    // 홀수인 데이터를 일괄 삭제
    {
        //// 벡터에서 중간 삭제는 비효율적이라 remove를 사용해보자
        //for (vector<int>::iterator it = v.begin(); it != v.end();)
        //{
        //    if (*it % 2 != 0)
        //        v.erase(it);
        //    else
        //        ++it;
        //    // 여담으로 조건이 걸린 삭제 반복은 변경을 내부에서 하자
        //}
        v.clear();

        v.push_back(1);
        v.push_back(4);
        v.push_back(3);
        v.push_back(5);
        v.push_back(8);
        v.push_back(2);
        // 1 4 3 5 8 2
        // 4 8 2    first   5 8 2
        // 필요한 데이터만 남겨두는 쪽으로 진행
        /*template<class ForwardIt, class UnaryPredicate>
        ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate p)
        {
            first = std::find_if(first, last, p);
            if (first != last)
                for (ForwardIt i = first; ++i != last; )
                    if (!p(*i))
                        *first++ = std::move(*i);
            return first;
            // 필요한 데이터까지 넣어두고 이제부터 필요없는 커서를 뱉어준다.
        }*/

        struct IsOdd
        {
            bool operator()(int n)
            {
                return (n % 2 != 0);
            }
        };
        // remove(v.begin(), v.end(), 4);
        // 여기서부턴 삭제해야할 데이터
        // erase를 해줘야함
        vector<int>::iterator it = remove_if(v.begin(), v.end(), IsOdd());
        v.erase(it, v.end());

        // v.erase(remove_if(v.begin(), v.end(), IsOdd()), v.end());
        // 주로 위처럼 쓰인다.

        int breakPoint = 2;
        
    }


    return 0;
}
