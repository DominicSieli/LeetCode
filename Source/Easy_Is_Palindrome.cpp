#include <string>
#include <ctype.h>
#include <iomanip>
#include <iostream>

bool IsPalindrome(std::string s)
{
	unsigned int l = 0;
	unsigned int r = s.length() - 1;

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

std::string s1 = "0a";
std::string s2 = "ab";
std::string s3 = "aBba";
std::string s4 = "a #a c -bbc, a:  a ";

int main()
{
	std::cout << std::boolalpha << IsPalindrome(s1) << '\n';
	std::cout << std::boolalpha << IsPalindrome(s2) << '\n';
	std::cout << std::boolalpha << IsPalindrome(s3) << '\n';
	std::cout << std::boolalpha << IsPalindrome(s4) << '\n';
}