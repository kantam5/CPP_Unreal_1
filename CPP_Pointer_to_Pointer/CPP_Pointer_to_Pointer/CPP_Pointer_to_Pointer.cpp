#include <iostream>
using namespace std;

void SetNumber(int* a)
{
	*a = 9;
}

void SetMessage(const char* a)
{
	a = "Bye";
	// readonly 데이터영역에 [B][y][e][\0]를 만들어서 시작주소를 a에 넣어주게 된다.
	// 결국 a라는 주소를 받는 바구니의 내용물을 Bye로 바꾼것 뿐 바뀌는게 없다.
}

void SetMessage(const char** a)
{
	*a = "Bye";
}

void SetMessage2(const char*& a)
{
	a = "WOW";
}

int main()
{
	int a = 0;
	SetNumber(&a);

	// Hello는 저멀리 readonly데이터 영역 .data영역에 [h][e][l][l][o][\0]
	// .data Bye주소[B][y][e][\0]
	// 시작 주소가 msg에 
	// 스택영역 msg[ Hello시작주소 ] << 8바이트
	const char* msg = "Hello";
	// [매개변수][RET][지역변수(msg(Hello주소)] [매개변수(a(Hello주소))][RET][지역변수]
	// [매개변수][RET][지역변수(msg(Hello주소)] [매개변수(a(Bye주소)][RET][지역변수]
	// [매개변수][RET][지역변수(msg(Hello주소)] 스택프레임 정리
	SetMessage(msg);
	//cout << msg << endl;

	// 주소를 담는 바구니 pp[ 주소1 ] = pp[ &msg ] << 8바이트
	// 주소로 들어가면 앞의 타입이 있는데 그것이 const char* 주소를 담는 바구니
	// 주소1[ 주소2 ] = msg[ Hello주소 ] << 8바이트
	// 주소2[ ] = Hello주소[ "Hello" ] << 1바이트
	const char** pp = &msg;
	// pp가 가지는 거는 const char*형의 주소를 담는 바구니의 주소

	// [매개변수][RET][지역변수(msg(Hello주소)] [매개변수(a(msg주소))][RET][지역변수]
	SetMessage(&msg);
	cout << msg << endl;

	// 다중 포인터 : 혼동스럽다.
	// 그냥 양파까기라고 생각하면 된다.
	// *을 하나씩 까면서 타고 간다고 생각하자.

	// [매개변수][RET][지역변수(msg(Hello주소)] [매개변수(a(msg주소))][RET][지역변수]
	SetMessage2(msg);
	cout << msg << endl;
	
	return 0;
}