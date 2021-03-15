#include <iostream>
using namespace std;

// 참조 기초
struct StatInfo
{
    int hp;         // +0
    int attack;     // +4
    int defence;    // +8
};

void CreateMonster(StatInfo* info)
{
    info->hp = 100;
    info->attack = 8;
    info->defence = 5;
}

// 특정 조건을 만족하는 몬스터를 찾는 함수
StatInfo* FindMonster()
{
    // T000 : Heap 영역에서 뭔가를 찾아봄
    // 찾았다!
    // return monster;
    
    return nullptr; // 못찾음
}

StatInfo globalInfo;
// 2) 주소 전달 방식
void PrintInfoByPtr(StatInfo* info)
{
    // 어지간해선 info가 nullptr인지 체크해보는게 좋다
    // 밑에서 크래시가 날 수도 있음
    if (info == nullptr)
        return;
    if (!info)
        return;

    cout << "-----------------------" << endl;
    cout << "HP;  " << info->hp << endl;
    cout << "ATK: " << info->attack << endl;
    cout << "DEF: " << info->defence << endl;
    cout << "-----------------------" << endl;

    // 별 뒤에 붙인다면?
    // StatInfo* const info
    // info라는 바구니의 내용물[주소]를 바꿀 수 없음
    // info는 주소값을 갖는 

    // 별 앞에 붙인다면?
    // const StatInfo* info
    // info가 가리키고 있는 바구니의 내용물을 바꿀 수 없음
    // 원격 바구니의 내용물을 바꿀 수 없음
    
    // 둘다 const를 붙여도 됨

    // info[주소값]    주소값[데이터]
    info = &globalInfo;     // 주소값을 바꾸거나
    info->hp = 10000;       // 주소값의 내부를 고치거나
}

// StatInfo 구조체가 1000바이트 짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사되는
// - (주소 전달) StatInfo*는 8바이트
// - (참조 전달) StatInfo&는 8바이트

// const를 붙여주자 참조같은 경우엔 어지간해선 const가 같이 붙는다.
void PrintInfoByRef(const StatInfo& info)
{
    cout << "-----------------------" << endl;
    cout << "HP;  " << info.hp << endl;
    cout << "ATK: " << info.attack << endl;
    cout << "DEF: " << info.defence << endl;
    cout << "-----------------------" << endl;

    // 신입이 왔다면 
    // info.hp = 10000; 바꿔버릴 수 있음 -> const로 막는다.
}

#define OUT
void ChangeInfo(OUT StatInfo& info)
{
    info.hp = 1000;
}

int main()
{
    StatInfo info;

    // 포인터 vs 참조 세기의 대결
    // 성능 : 똑같음~
    // 편의성 : 참조

    // 1) 편의성 관련
    // 편의성이 좋다는게 꼭 장점은 아니다.
    // 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄 수 있는데
    // 참조는 자연스럽게 모르고 지나칠 수도 있음
    // ex) 마음대로 고친다면
    // const를 사용해서 마음대로 고치는 부분 개선 가능

    // 참고로 포인터도 const를 사용 가능
    // * 기준으로 앞에 붙이느냐, 뒤에 붙이느냐에 따라 의미가 달라진다.

    // 2) 초기화 여부
    // 참조 타입은 바구니의 2번째 이름(별칭?)
    // -> 참조하는 대상이 없으면 안됨
    // 반면 포인터는 그냥 어떤 주소라는 의미
    // -> 대상이 실존하지 않을 수도 있음
    // 포인터에서 '없다'는 의미로? -> nullptr
    // 참조 타입은 이런 nullptr이 없다.

    StatInfo* pointer = nullptr;
    // pointer = &info;
    PrintInfoByPtr(pointer);   // 원본을 넘겨준다는걸 확실히 알 수 있음

    StatInfo& reference = info;
    PrintInfoByRef(reference);    // 원본인지 잘 알 수 없음

    // 그래서 결론은?
    // 사실 Team By Team
    // ex) 구글에서의 오픈소스는 무조건 포인터
    // ex) 언리얼 엔진에선 reference도 이용

    // 이 강의 저자의 스타일
    // - 없는 경우도 고려해야 한다면 pointer를 사용하는게 좋다
    // - 바뀌지 않고 읽는 용도(readonly)만 사용하면 const ref로 사용
    // - 그 외 일반적으로 ref (일시적으로 호출할 때 OUT을 붙인다)
    // -- 단, 다른 사람이 pointer를 만들어 놓은걸 이어서 만든다면, 계속 pointer로 (섞지 않음)
    ChangeInfo(OUT info);   // 값이 바뀔수 있다는 것을 표현

    // Bouns) 포인터로 사용하던걸 참조로 넘겨주려면? *를 붙인다
    // pointer[주소(&info)]   reference, info[데이터] 
    StatInfo& ref = *pointer;
    PrintInfoByRef(*pointer);

    // Bouns) 참조로 사용하던걸 포인터로 넘겨주려면? &를 붙인다
    // pointer[주소(&info)]   reference, info[데이터]
    StatInfo* ptr = &reference;
    PrintInfoByPtr(&reference);

    return 0;
}