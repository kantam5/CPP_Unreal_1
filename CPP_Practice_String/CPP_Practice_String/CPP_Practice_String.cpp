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
    /*int i = 0;
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

    return dest;*/

    /*int len = StrLen(dest);
    int i = 0;
    while (src[i] != '\0')
    {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    
    return dest;*/

    while (*dest != '\0')
    {
        dest++;
    }

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return dest;
}

// 두 문자열을 비교하는 함수
int StrCmp(char* str1, char* str2)
{
    /*int i = 0;
    
    while (str1[i] != '\0')
    {
        if (str1[i] - str2[i] > 0)
            return 1;
        else if (str1[i] - str2[i] < 0)
            return -1;

        i++;
    }

    if (str2[i] == '\0')
        return 0;*/

    int i = 0;

    while (str1[i] != '\0' || str2[i] != '\0')
    {
        if (str1[i] > str2[i])
            return 1;
        if (str1[i] < str2[i])
            return -1;
        i++;
    }

    return 0;
}

// 문자열 뒤집기
void ReverseStr(char* str)
{
    int len = StrLen(str);

    for (int i = 0; i < len / 2; i++)
    {
        int temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main()
{
    const int BUF_SIZE = 100;
    
    // [H] [e] [l] [l] [o] [\0] [][][][]
    char a[BUF_SIZE] = "Hella";
    char b[BUF_SIZE] = "Hella";


    // int len = StrLen(a);
    // cout << len;

    // StrCpy(b, a);

    // StrCat(a, b);

    // int value = StrCmp(a, b);

    
    ReverseStr(a);
    for (int i = 0; i < BUF_SIZE; i++)
    {
        cout << a[i];
    }

    return 0;
}