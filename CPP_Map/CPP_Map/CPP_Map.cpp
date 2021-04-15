#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>

// map
// 사용 빈도 높음

class Player
{
public:
    Player() : _playerId(0)
    {

    }
    Player(int playerId) : _playerId(playerId)
    {

    }

public:
    int _playerId;
};

template<typename T1, typename T2>
struct Pair
{
    T1 t1;
    T2 t2;
};

int main()
{
    // 연관 컨테이너
    // 왜 기존의 벡터, 리스트 같은 선형 컨테이너로는 힘든지
 //   vector<Player*> v;

 //   // 10만명이 입장
 //   for (int i = 0; i < 100000; i++)
 //   {
 //       Player* p = new Player(i);
 //       v.push_back(p);
 //   }
 //   // 5만명이 퇴장
 //   for (int i = 0; i < 50000; i++)
 //   {
 //       int randIndex = rand() % v.size();
 //       Player* p = v[randIndex];
 //       delete p;

 //       v.erase(v.begin() + randIndex);
 //   }


 //   // Q) ID = 1만인 Player를 찾아주세요.
	//bool found = false;
 //   for (int i = 0; i < v.size(); i++)
 //   {
 //       if (v[i]->_playerId == 10000)
 //       {
 //           found = true;
 //           break;
 //       }
 //   }

    // vector, list의 치명적인 단점
    // -> 원하는 조건에 해당하는 데이터를 빠르게 찾을 수 없다.

    // map : 균형 이진 트리 (AVL)
    // - 노드 기반

    class Node
    {
    public:
        Node* _left;
        Node* _right;
        // value
        pair<int, Player*> _data;
        // int _key;       
        // Player* _value;
    };
    

    srand(static_cast<unsigned int>(time(nullptr)));
    map<int, int> m;

    // erase에서 뱉어주는 값
    pair<map<int, int>::iterator, bool> ok;
    // 똑같은 key로 몇번 넣으면?
    // 두번째 요청은 무시
    // 바꾸고 싶다면 찾아서 바꿔
    ok = m.insert(make_pair(1, 100));
    // 뱉어주는데 성공했으므로 second의 값이 true
    ok = m.insert(make_pair(1, 200));
    // 뱉어주는데 실패했으므로 second의 값이 false

    // 10만명
    for (int i = 0; i < 100000; i++)
    {
        m.insert(pair<int, int>(i, i * 100));
    }

    // 5만명 퇴장
    for (int i = 0; i < 50000; i++)
    {
        int randvalue = rand() % 50000;
        // erase by key
        m.erase(randvalue); 
    }

    // Q) Id가 1만인 Player 찾고 싶다.
    // A) 매우 빠르게 찾을 수 있음
    // unsigned int count = 0;
    // count = m.erase(10000);
    // count = m.erase(10000);
    // 같은 값을 여러번 삭제해도 상관없다. 같은 값이 삭제되면 0을 반환

    // 10000번째가 없을 수도 있음
    //map<int, int>::iterator findIt = m.find(10000);
    //// 값이 없을 떄는 m.end()값을 갖는다.
    //if (findIt != m.end())
    //{
    //    cout << "찾음" << endl;
    //}
    //else
    //{
    //    cout << "못 찾음" << endl;
    //}

    // map 순회
    // [] 사용 불가 iterator로 해야됨
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        pair<const int, int>& p = (*it);
        int key = it->first;  //(*it).first;  it->first
        int value = it->second;   // (*it).second;  it->second

        cout << key << " " << value << endl;
    }

    // 없으면 추가, 있으면 수정
    map<int, int>::iterator findIt = m.find(10000);
    if (findIt != m.end())
    {
        findIt->second = 200;
    }
    else
    {
        m.insert(make_pair(10000, 200));
    }
    // 없으면 추가, 있으면 수정 ver.2
    // m[5] = 200;     // 5가 key
    // 5가 없으면 200으로 추가, 있다면 200으로 수정

    // [] 연산자 사용할 떄 주의
    // 대입을 하지 않아도 (key/value) 형태의 데이터가 추가된다.
    for (int i = 0; i < 10; i++)
    {
        cout << m[i] << endl;
        // 계속 추가된다 value는 0으로
    }

    // 넣고 (insert, [])
    // 빼고 (erase)
    // 찾고 (find, [])
    // 반복자 (map::iterator, (*it) = pair<key, value>)

    return 0;
}
