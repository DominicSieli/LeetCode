#include <stdio.h>
#include <limits.h>

int Reverse_Integer(int x)
{
	int rev = 0;
	int pop = 0;

	while(x != 0)
	{
		pop = x % 10;
		x /= 10;

		if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
		if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
		rev = rev * 10 + pop;
	}

	return rev;
}

int main()
{
	printf("%d", Reverse_Integer(123));
	printf("\n");
	printf("%d", Reverse_Integer(-123));
}