#include <cstdio>
#include <cwchar>
int main()
{
	char english[] = "a book holds a house of gold";
	char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b"; // unicode for wide character string like chinese
	printf("english sentence = %s\n", english);
	wprintf(L"chinese sentence is %s\n",chinese );
	return 0;
}
