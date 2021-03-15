#include <iostream>
using namespace std;

void Test(int a)
{
	a++;
}

// 배열을 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환한다.
// char a[0]  ->  char *a
// 즉 배열 전체를 넘긴게 아니라 시작 주소만 넘긴다.
void Test(char a[])
{
	a[0] = 'x';
}

int main()
{
	// .data 주소[H][e][l][l][o][ ][W][o][r][l][d][\0]
	// test1[주소] << 8바이트 위의 시작주소가 들어있다.
	// 단순히 원격으로 가리키고만 있다
	const char* test1 = "Hello World";
	// test1[0] = 'R'; 불가함


	// .data 주소[H][e][l][l][o][ ][W][o][r][l][d][\0]
	// [][][][][][][][][][][][] 12바이트의 닭장
	// 4바이트씩 위의 Hello wolrd를 복사하여 넣는다.
	char test2[] = "Hello World";
	// test2[0] = 'R';
	// cout << test2 << endl;

	

	// 포인터는 주소를 담는 바구니
	// 배열은 닭장 그자체로 같은 데이터짜리 붙어있는 바구니 모음
	// - 다만 [배열 이름]은 바구니 모음의 [시작 주소]
	// - 배열 이름은 포인터가 아니라 단순히 시작 주소가 담겨있다.

	// 배열을 함수의 인자로 넘기게 된다면
	int a = 0;
	// [매개변수][RET][지역변수(a=0)]  [매개변수(a=0)][RET][지역변수]
	Test(a);

	Test(test2);
	cout << test2 << endl;
	

	return 0;
}
