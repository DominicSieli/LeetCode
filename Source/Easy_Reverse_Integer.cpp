#include <stdio.h>
#include <limits.h>

int ReverseInteger(int x)
{
	int xlast = 0;
	int reverse = 0;

	while(x != 0)
	{
		xlast = x % 10;
		x /= 10;

		if(reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && xlast > 7)) return 0;
		if(reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && xlast < -8)) return 0;
		reverse = reverse * 10 + xlast;
	}

	return reverse;
}

int main()
{
	printf("%d", ReverseInteger(123));
	printf("\n");
	printf("%d", ReverseInteger(-123));
}