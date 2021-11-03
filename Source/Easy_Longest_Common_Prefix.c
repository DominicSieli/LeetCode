#include <stdio.h>

char* LongestCommonPrefix(char** strings, int size)
{
	unsigned int i = sizeof(strings[0]) / sizeof(char);

	for(unsigned int s = 0; s < size - 1; s++)
	{
		for(unsigned int c = 0; c < i; c++)
		{
			unsigned int s1 = sizeof(strings[s]) / sizeof(char);
			unsigned int s2 = sizeof(strings[s+1]) / sizeof(char);
			if(c >= s1) {i = s1; break;}
			if(c >= s2) {i = s2; break;}
			if(strings[s][c] != strings[s+1][c]) i = c;
		}
	}

	char* result = (char*)malloc(sizeof(char*) * i);
	memcpy(result, strings[0], i);
	result[i] = '\0';
	return result;
}

const char* string1[] = {"a"};
const char* string2[] = {"",""};
const char* string3[] = {"ab","a"};
const char* string4[] = {"flower","flow","flight"};

int main()
{
	printf(LongestCommonPrefix(string1, 1)); printf("\n");
	printf(LongestCommonPrefix(string2, 2)); printf("\n");
	printf(LongestCommonPrefix(string3, 2)); printf("\n");
	printf(LongestCommonPrefix(string4, 3)); printf("\n");
}