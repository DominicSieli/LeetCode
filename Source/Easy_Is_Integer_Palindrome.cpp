#include <iomanip>
#include <iostream>
#include <bits/stdc++.h>

bool IsIntergerPalindrome(int x)
{
	unsigned int n;
	if(x < 0) return false;
	if(x > 0) n = (int)std::log10(x);

	while(x != 0)
	{
		if(x % 10 != (int)(x / (int)std::pow(10, n))) return false;
		x = x % (int)std::pow(10, n);
		x = (int)(x / 10);
		n -= 2;
	}

	return true;
}

int main()
{
	std::cout << std::boolalpha << IsIntergerPalindrome(12122121);
}