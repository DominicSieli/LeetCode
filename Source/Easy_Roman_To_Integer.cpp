#include <map>
#include <string>
#include <iostream>

int Roman_To_Integer(std::string s)
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

//std::string s = "IV";
//std::string s = "IX";
//std::string s = "III";
//std::string s = "LVIII";
//std::string s = "MMCXVI";
std::string s = "MCMXCIV";

int main()
{
	std::cout << Roman_To_Integer(s);
}