#include <string>
#include <vector>
#include <iostream>

std::string LongestCommonPrefix(std::vector<std::string>& strings)
{
	unsigned int i = strings[0].length();

	for(unsigned int s = 0; s < strings.size() - 1; s++)
	{
		for(unsigned int c = 0; c < i; c++)
		{
			if(c >= strings[s].length()) {i = strings[s].length(); break;}
			if(c >= strings[s+1].length()) {i = strings[s+1].length(); break;}
			if(strings[s][c] != strings[s+1][c]) i = c;
		}
	}

	return strings[0].substr(0, i);
}

std::vector<std::string> string1({"a"});
std::vector<std::string> string2({"",""});
std::vector<std::string> string3({"ab","a"});
std::vector<std::string> string4({"flower","flow","flight"});

int main()
{
	std::cout << LongestCommonPrefix(string1) << '\n';
	std::cout << LongestCommonPrefix(string2) << '\n';
	std::cout << LongestCommonPrefix(string3) << '\n';
	std::cout << LongestCommonPrefix(string4) << '\n';
}