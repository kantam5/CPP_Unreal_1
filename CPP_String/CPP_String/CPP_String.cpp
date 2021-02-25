#include <iostream>
using namespace std;

// 문자와 문자열
// bool은 그냥 정수지만 참 거짓을 나타내기 위해 사용
// char도 그냥 정수지만 문자 의미를 나타내기 위해 사용

// char : 알파벳 / 숫자 문자
// wchar_t : 유니코드 문자를 나타낸다. 

// char에 숫자 입력시 ASCII로 출력 

// 문자의 의미로 ''을 사용
char ch = 'a';
char ch2 = '1'; // 1의 ascii값이 입력된다.
char ch3 = 'a' + 1; //98 번이 저장

// 전 세계 모든 문자에 대해 유일 코드를 부여하는 것이 유니코드
// 참고) 유니코드에서 가장 많은 번호를 차지하는게 한국어/중국어

// 유니코드는 표기 방식이 여러가지 대표적으로 UTF8, UTF16
// UTF8
// - 알파벳, 숫자 1바이트 (ASCII 동일한 번호)
// - 유럽 지역의 문자는 2바이트
// - 한글, 한자 등은 3바이트
// UTF16
// - 알파벳, 숫자, 한글, 한자 등 거의 대부분 2바이트
// - 매우 애외적인 고대 문자만 4바이트 (사실상 무시해도 됨)

wchar_t wch = 0xc548; //'안';

// Escape Sequence
// 표기하기 애매한 애들을 표현
// \t = 아스키코드9번 = Tab
// \n = 아스키코드10번 = LineFeed(한줄 아래로)
// \r = 아스키코드13번 = Carriagereturn(커서 <<)
// \' = '

// 문자열
// 문자들이 열을 지어서 모여 있는 것 (문자 배열)
// 정수 (1~8바이트) 고정 길이로
// 문자배열들이 있고 끝에 NULL가 저장되어 있어서 문자열 끝을 표현
// -> \0

// char str[] = { 'h', 'e', 'l', 'l', 'o' };
char str2[] = "Hello World"; // 마지막에 null이 잡혀있어서 12자
wchar_t str3[] = L"Hello World";

int main()
{
    char str[] = { 'h', 'e', 'l', 'l', 'o', '\0'};
    // stack 영역에서 문자열을 생성시 끝에 NULL이 안 들어가 있어서
    // 이상하게 나옴
    cout << ch << endl;
    cout << ch2 << endl;
    cout << ch3 << endl;

    // cout은 char 전용이라 wchar_t는 제대로 안나옴
    wcout.imbue(locale("kor"));
    wcout << wch << endl;

    cout << str << endl;
    cout << str2 << endl;

}
