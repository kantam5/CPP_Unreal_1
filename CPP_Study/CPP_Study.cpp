#include <iostream>
using namespace std;

// [타입] [이름];
// [타입] [이름] = [초기값];

// 0이 아닌 초기값이 있으면 .data영역
// 초기값이 0이거나, 초기값이 없으면 .bss영역
int hp = 100;

char a; //1바이트 (-128 ~ 127)
short b; //2바이트 (-32768 ~ 32767)
int c; // 4바이트 (-21.4억 ~ 21.4억)
__int64 d; // 8바이트 (long long) (겁나 크다)

unsigned char ua; //1바이트 (0 ~ 255)
unsigned short ub; //2바이트 (0~ 655355)
unsigned int uc; // 4바이트 (0 ~ 42.9억)
unsigned __int64 ud; // 8바이트 (long long) (겁나 크다)
// 이론적으로 양수만 존재할 수 있는 데이터 -> 레벨
// -> unsigned와 signed 사이의 변환 

// 메모리가 부족할 수 있는 프로그램은 사이즈를 줄이는게 좋다. 
// -> 갖가지 게임들 -> 온라인 이면 매초마다 몇 개의 바이트 낭비

int main()
{
	b = 32767;
	b += 1;
	cout << "체력이 " << hp << "남았습니다." << endl;
	cout << b << endl;	// -32768 -> 가장 높은 비트가 1이되어 음수
	// 정수 오버플로우, 정수 언더플로우
	ub = 0;
	ub -= 1;
	cout << ub << endl;
}
