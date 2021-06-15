#include <string>
#include <vector>
#include <iostream>

std::string Longest_Common_Prefix(std::vector<std::string>& strs)
{
	unsigned int i = strs[0].length();

	for(unsigned int s = 0; s < strs.size() - 1; s++)
	{
		for(unsigned int c = 0; c < i; c++)
		{
			if(c >= strs[s].length()) {i = strs[s].length(); break;}
			if(c >= strs[s+1].length()) {i = strs[s+1].length(); break;}
			if(strs[s][c] != strs[s+1][c]) i = c;
		}
	}

	return strs[0].substr(0, i);
}

std::vector<std::string> strs1({"a"});
std::vector<std::string> strs2({"",""});
std::vector<std::string> strs3({"ab","a"});
std::vector<std::string> strs4({"flower","flow","flight"});

int main()
{
	std::cout << Longest_Common_Prefix(strs1) << '\n';
	std::cout << Longest_Common_Prefix(strs2) << '\n';
	std::cout << Longest_Common_Prefix(strs3) << '\n';
	std::cout << Longest_Common_Prefix(strs4) << '\n';
}