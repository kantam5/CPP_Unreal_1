#include <iostream>
using namespace std;

// 1) 포인터 vs 배열
// 2) 주의사항 (마음가짐)
// 어지간해선 스택과 관련된 주소를 넘겨주는건 하지말자 절대로
int& TestRef()
{
    int a = 1;
    return a;
}

int* TestPointer() {
    int a = 1;
    return &a;
}

void TestWrong(int* ptr)
{
    int a[100] = {};
    a[99] = 0xAAAAAAAA;
    *ptr = 0x12341234;
}

int main()
{
    // 주소를 담는 바구니
    // 진퉁은 저 멀리 어딘가에 있음
    // p는 단지 그 곳으로 워프하는 포탈
    int* p;

    // 진짜배기 원조 데이터
    // 닭장처럼 데이터를 묶음( 엄청 많고 거대함 )
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    // 상당히 많은 사람들이 배열 = 포인터 라 착각하는 경향이 있음
    // - [배열의 이름]은 배열의 시작 주소값을 가리키는 TYPE* 포인터로 변환 가능
    p = arr;

    // - [TYPE형 1차원 배열]과 [TYPE*형 포인터]는 완전히 호환이 된다.
    cout << p[0] << endl;
    cout << arr[0] << endl;
    cout << p[2] << endl;
    cout << arr[2] << endl;
    cout << *p << endl;
    cout << *arr << endl;
    cout << *(p + 3) << endl;
    cout << *(arr + 3) << endl;

    // 지옥 굳이 외울필요 없음
    // 2차원 배열 vs 다중 포인터
    // [1][2][3][4]
    int arr2[2][2] = { {1,2}, {3, 4} };

    // 주소2[ 정수 ] << 4바이트
    // 주소1[ 주소2 ] -> 실은 주소1[ 00000001 ]
    // pp[ 주소1 ]

    // [1][2]
    // [ 주소 ]
    int(*p2)[2] = arr2;
    cout << (*p2)[0] << endl;
    cout << (*p2)[1] << endl;
    cout << (*(p2 + 1))[0] << endl;
    cout << (*(p2 + 1))[1] << endl;

    cout << p2[0][0] << endl;
    cout << p2[0][1] << endl;
    cout << p2[1][0] << endl;
    cout << p2[1][1] << endl;
    
    // [매개변수][RET][지역변수] [매개변수][RET][지역변수(a)]
    // [매개변수][RET][지역변수] 스택 프레임이 정리되어 유효하지 않아짐
    int* pointer = TestPointer();

    // 주소가 끝까지 유효한지 를 생각하자.
    TestWrong(pointer);
    *pointer = 123;

    return 0;
}
