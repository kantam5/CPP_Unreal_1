#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>

// deque

// vector : 동적 배열
// list : 이중 연결 리스트
// deque : double-ended-queue
// [   ] 벡터와는 다르게 용량이 다하면 메모리 상으로 떨어진 배열을 생성 
// [   ]


int main()
{
	// 시퀀스 컨테이너 (Sequence container)
	// 데이터가 삽입 순서대로 나열되는 형태
	// vector list dequ

	//deque<int> dq;
	//dq.push_back(1);
	//// capacity는 없음
	//dq.push_front(2);
	//cout << dq[0] << endl;		// 임의 접근 가능

	// vector처럼 배열 기반으로 동작
	// 다만 메모리 할당 정책이 다르다
	
	// vector 
	// [ 12    ]
	// [ 12           ]

	// deque
	// [1 1 1]
	// [1 1 1 2]  
	// [1 1 1 2]   [2      ]
	// [3]  [1 1 1 2]   [2      ]
	// [3 3]  [1 1 1 2]   [2      ]

	vector<int> v(3, 1);
	deque<int> dq(3, 1);

	v.push_back(2);
	v.push_back(2);
	
	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);

	// - deque의 동작 원리
	// - 중간 삽입/삭제(bad/ bad) 중간에 있는 데이터가 변경되면 나머지가 옮겨져야됨
	// - 처음/끝 삽입/삭제 (good/good) 계속 밀어주면 된다.
	// - 임의 접근 (good)

	deque<int>::iterator it;
	// _Size_type _Block = _Mycont->_Getblock(_Myoff);
	// _Size_type _Off = _Myoff % _DEQUESIZ;
	// return _Mycont->_Map[_Block][_Off];
	// 몇동 몇호를 테이블로 가지고 있다.
	// 결국 중간에 비어있는 값이 없다.
	// -> 중간 삽입 삭제가 bad인 이유 임의 접근을 살린다.


	return 0;

}
