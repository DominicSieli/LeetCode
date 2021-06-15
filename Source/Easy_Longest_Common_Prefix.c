#include <stdio.h>

char* Longest_Common_Prefix(char** strs, int strsSize)
{
	unsigned int i = sizeof(strs[0]) / sizeof(char);

	for(unsigned int s = 0; s < strsSize - 1; s++)
	{
		for(unsigned int c = 0; c < i; c++)
		{
			unsigned int s1 = sizeof(strs[s]) / sizeof(char);
			unsigned int s2 = sizeof(strs[s+1]) / sizeof(char);
			if(c >= s1) {i = s1; break;}
			if(c >= s2) {i = s2; break;}
			if(strs[s][c] != strs[s+1][c]) i = c;
		}
	}

	char* result = (char*)malloc(sizeof(char*) * i);
	memcpy(result, strs[0], i);
	result[i] = '\0';
	return result;
}

const char* strs1[] = {"a"};
const char* strs2[] = {"",""};
const char* strs3[] = {"ab","a"};
const char* strs4[] = {"flower","flow","flight"};

int main()
{
	printf(Longest_Common_Prefix(strs1, 1)); printf("\n");
	printf(Longest_Common_Prefix(strs2, 2)); printf("\n");
	printf(Longest_Common_Prefix(strs3, 2)); printf("\n");
	printf(Longest_Common_Prefix(strs4, 3)); printf("\n");
}