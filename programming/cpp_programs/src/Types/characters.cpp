#include <cstdio>
#include <uchar.h>
#include <iostream>

int main()
{
    char a = 'A'; // normal ASCII character : can be unsigned or signed
    wchar_t b = L'B'; // wide character : supports non-English characters
    char16_t c = 'A'; // 16 bit Unicode character
    char32_t d = 'A'; // 32 bit unicode character
    printf("%c %lc\n", a, b);
    printf("%lc %lc\n",c,d);
    // unicode codes 
    //wchar_t unicode_c = '\u0041';
    //wchar_t unicode_d = '\U0001F37A';
    //wchar_t unicode_c = L'\u0041'; 'A' being UTF-8 encoded narrow character cannot be represented as UTF-16 character
    //wchar_t wide_char = L'\u0041';  // Wide character literal
    //std::wcout << wide_char << std::endl;  // Outputs 'A'
   
    std::cout << "\U0001F37A" << std::endl; // beer mug symbol
    
    return 0;
}