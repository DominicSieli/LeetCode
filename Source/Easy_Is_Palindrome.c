#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool Is_Palindrome(char* s)
{
	unsigned int l = 0;
	unsigned int r = strlen(s) - 1;

	while(l < r)
	{
		while(l < r && !isalnum(s[l])) l++;
		while(l < r && !isalnum(s[r])) r--;
		if(tolower(s[l]) != tolower(s[r])) return false;
		if(l < r) l++;
		if(l < r) r--;
	}

	return true;
}

char* s1 = "0a";
char* s2 = "ab";
char* s3 = "aBba";
char* s4 = "a #a c -bbc, a:  a ";

int main()
{
	printf("%s\n", Is_Palindrome(s1) ? "true" : "false");
	printf("%s\n", Is_Palindrome(s2) ? "true" : "false");
	printf("%s\n", Is_Palindrome(s3) ? "true" : "false");
	printf("%s\n", Is_Palindrome(s4) ? "true" : "false");
}