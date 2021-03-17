#include <iostream>
using namespace std;


// str이라는 문자열의 길이를 반환
int StrLen(const char* str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;

    return i;
}

// 문자열 복사 함수
#pragma warning(disable: 4996)  // strcpy 함수 오류 무시
char* StrCpy(char* dest, char* src)
{
    //int i = 0;
    //
    //while (src[i] != '\0')  // == while (src[i])
    //{
    //    dest[i] = src[i];
    //    i++;
    //}
    //dest[i] = '\0';

    //return dest;
    
    char* ret = dest;
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return ret;
}

// 문자열 덧붙이는 함수
char* StrCat(char* dest, char* src)
{
    int i = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    int j = 0;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';

    return dest;
}

int main()
{
    const int BUF_SIZE = 100;
    
    // [H] [e] [l] [l] [o] [\0] [][][][]
    char a[BUF_SIZE] = "Hello";
    char b[BUF_SIZE] = "Hello";


    // int len = StrLen(a);
    // cout << len;

    //StrCpy(b, a);

    StrCat(a, b);

    return 0;
}