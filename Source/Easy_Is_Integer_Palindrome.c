#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

bool Is_Interger_Palindrome(int x)
{
	if(x < 0) return false;

	int rev = 0;
	int rev_x = x;

	while(rev_x != 0)
	{
		int pop = rev_x % 10;
		rev_x /= 10;

		if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return false;
		if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return false;
		rev = rev * 10 + pop;
	}

	rev_x = x;

	while(rev_x != 0)
	{
		int x_pop = rev_x % 10;
		int rev_pop = rev % 10;
		rev /= 10;
		rev_x /= 10;

		if(x_pop != rev_pop)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	printf("%s", Is_Interger_Palindrome(121) ? "true" : "false");
}