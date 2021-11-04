#include <stack>
#include <string>
#include <iomanip>
#include <iostream>

bool ValidParentheses(std::string s)
{
	if(s.length() % 2 != 0) return false;

	std::stack<char> stk;

	for(char c : s)
	{
		if(c == '(' || c == '[' || c == '{') stk.push(c);

		if(stk.empty())
		{
			if(c == ')' || c == ']' || c == '}') return false;
		}

		if(!stk.empty())
		{
			if(c == ')' && stk.top() == '(') stk.pop();
			else if(c == ')' && stk.top() != '(') return false;

			if(c == ']' && stk.top() == '[') stk.pop();
			else if(c == ']' && stk.top() != '[') return false;

			if(c == '}' && stk.top() == '{') stk.pop();
			else if(c == '}' && stk.top() != '{') return false;
		}
	}

	return stk.empty();
}

std::string s = {"([}}])"};

int main()
{
	std::cout << std::boolalpha << ValidParentheses(s);
}