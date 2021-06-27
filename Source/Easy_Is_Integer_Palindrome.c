#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool Is_Interger_Palindrome(int x)
{
	unsigned int n;
	if(x < 0) return false;
	if(x > 0) n = (int)log10(x);

	while(x != 0)
	{
		if(x % 10 != (int)(x / (int)pow(10, n))) return false;
		x = x % (int)pow(10, n);
		x = (int)(x / 10);
		n -= 2;
	}

	return true;
}

int main()
{
	printf("%s", Is_Interger_Palindrome(12122121) ? "true" : "false");
}