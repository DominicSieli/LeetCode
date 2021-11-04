#include <map>
#include <string>
#include <iostream>

int RomanToInteger(std::string s)
{
	int integer = 0;
	std::map<char, int> numerals;

	numerals['I'] = 1;
	numerals['V'] = 5;
	numerals['X'] = 10;
	numerals['L'] = 50;
	numerals['C'] = 100;
	numerals['D'] = 500;
	numerals['M'] = 1000;

	for(int i = 0; i < s.length(); i++)
	{
		if(i + 1 >= s.length())
		{
			integer += numerals[s[i]];
		}

		if(i + 1 < s.length())
		{
			if(numerals[s[i]] >= numerals[s[i + 1]]) integer += numerals[s[i]];
			if(numerals[s[i]] < numerals[s[i + 1]]) {integer += numerals[s[i + 1]] - numerals[s[i]]; i++;}
		}
	}

	return integer;
}

std::string s1 = "IV";
std::string s2 = "IX";
std::string s3 = "III";
std::string s4 = "LVIII";
std::string s5 = "MMCXVI";
std::string s6 = "MCMXCIV";

int main()
{
	std::cout << RomanToInteger(s1) << '\n';
	std::cout << RomanToInteger(s2) << '\n';
	std::cout << RomanToInteger(s3) << '\n';
	std::cout << RomanToInteger(s4) << '\n';
	std::cout << RomanToInteger(s5) << '\n';
	std::cout << RomanToInteger(s6) << '\n';
}