#include <stdio.h>

int Numerals(char c)
{
	switch(c)
	{
		case 'I' : return 1;
		case 'V' : return 5;
		case 'X' : return 10;
		case 'L' : return 50;
		case 'C' : return 100;
		case 'D' : return 500;
		case 'M' : return 1000;
	}

	return 0;
}

int RomanToInteger(char* s)
{
	int integer = 0;

	for(int i = 0; i < strlen(s); i++)
	{
		if(i + 1 >= strlen(s))
		{
			integer += Numerals(s[i]);
		}

		if(i + 1 < strlen(s))
		{
			if(Numerals(s[i]) >= Numerals(s[i + 1])) integer += Numerals(s[i]);
			if(Numerals(s[i]) < Numerals(s[i + 1])) {integer += Numerals(s[i + 1]) - Numerals(s[i]); i++;}
		}
	}

	return integer;
}

char* s1 = "IV";
char* s2 = "IX";
char* s3 = "III";
char* s4 = "LVIII";
char* s5 = "MMCXVI";
char* s6 = "MCMXCIV";

int main()
{
	printf("%d\n", RomanToInteger(s1));
	printf("%d\n", RomanToInteger(s2));
	printf("%d\n", RomanToInteger(s3));
	printf("%d\n", RomanToInteger(s4));
	printf("%d\n", RomanToInteger(s5));
	printf("%d\n", RomanToInteger(s6));
}