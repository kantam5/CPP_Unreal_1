#include <iostream>
using namespace std;
#include <set>
#include <map>
// set, multimap, multiset


int main()
{
    // 넣고
    // 빼고
    // 찾고
    // 순회하고
    // set은 key = value인 map
    set<int> s;
 
    s.insert(10);   // map과 달리 pair를 넣을 필요 없음
    s.insert(2); 
    s.insert(22); 
    s.insert(43); 
    s.insert(4); 
    s.insert(7); 
    s.insert(11); 
    s.insert(9); 

    // 빼고
    s.erase(40);
    
    // 찾고
    set<int>::iterator findIt = s.find(22);
    if (findIt == s.end())
        cout << "못찾음" << endl;
    else
        cout << "찾음" << endl;

    // s[10] = 10;      value를 따로 관리하는게 아니기에 [] 사용 못함

    // 순회하고
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << (*it) << endl;
    }

    cout << "---------------------------------" << endl;

    multimap<int, int> mm;

    // 넣고
    // 같은키에 여러 value를 가질 수 있다.
    mm.insert(make_pair(1, 100));
    mm.insert(make_pair(1, 200));
    mm.insert(make_pair(1, 300));
    mm.insert(make_pair(2, 400));
    mm.insert(make_pair(2, 500));

    // mm[1] = 50;  사용 불가

    //// 빼고
    //// mm.erase(1);        // 1은 싹다 날라감
    //unsigned int count = mm.erase(1);   // count는 여러 값이 될 수 있다.

    //// 찾고 
    //multimap<int,int>::iterator itFind = mm.find(1);
    //if (itFind != mm.end())
    //{
    //    mm.erase(itFind);       // 하나만 날라감
    //}

    // 순회
    pair<multimap<int, int>::iterator, multimap<int, int>::iterator> itPair;
    itPair = mm.equal_range(1);  // iterator을 pair쌍으로 뱉어줌
    // 1이라는 값이 시작하는 iterator을 first로 끝난 다음 iterator을 second로 뱉어줌

    multimap<int, int>::iterator itBegin = mm.lower_bound(1);  // 1이 시작되는 iterator를 반환
    multimap<int, int>::iterator itEnd = mm.upper_bound(1);  // 1이 끝난 다음의 iterator를 반환

    for (multimap<int, int>::iterator it = itPair.first; it != itPair.second; ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << "---------------------------------" << endl;

    multiset<int> ms;
    // 넣고
    ms.insert(100);
    ms.insert(100);
    ms.insert(100);
    ms.insert(200);
    ms.insert(200);

    // 찾고
    multiset<int>::iterator findIt2 = ms.find(100);   // 한개만 찾아줌
    
    pair<multiset<int>::iterator, multiset<int>::iterator> itPair2 = ms.equal_range(100);    // multimap과 동일함
    multiset<int>::iterator itBegin2 = ms.upper_bound(100);
    multiset<int>::iterator itEnd2 = ms.lower_bound(100);


    for (multiset<int>::iterator it = itPair2.first; it != itPair2.second; ++it)
    {
        cout << *it << endl;
    }




    return 0;
}

